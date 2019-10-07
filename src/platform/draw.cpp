namespace platform
{

static void handleResize(int w, int h)
{
    GPU_SetWindowResolution(w, h);

    int glWidth, glHeight;   // Actual screen pixels
    int sdlWidth, sdlHeight; // Pixels reported by OS
    SDL_GL_GetDrawableSize(pctx->window, &glWidth, &glHeight);
    SDL_GetWindowSize(pctx->window, &sdlWidth, &sdlHeight);

    pctx->scale = initialScale * glWidth / sdlWidth;
    pctx->scaleDiff = glWidth / sdlWidth;
    pctx->windowWidth = glWidth;
    pctx->windowHeight = glHeight;
    pctx->tilesWidth = pctx->windowWidth / (tileWidth * pctx->scale);
    pctx->tilesHeight = pctx->windowHeight / (tileHeight * pctx->scale);
    pctx->textWidth = pctx->windowWidth / (charWidth * pctx->scale);
    pctx->textHeight = pctx->windowHeight / (charHeight * pctx->scale);
}

static void initRender()
{
    int flags = GPU_DEFAULT_INIT_FLAGS | SDL_WINDOW_SHOWN |
        SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI;

    pctx->target = GPU_Init(initialWidth, initialHeight, flags);
    pctx->window = SDL_GetWindowFromID(pctx->target->context->windowID);
    handleResize(initialWidth, initialHeight);

    pctx->tilesImage = GPU_LoadImage("assets/tiles16x16.png");
    pctx->textImage = GPU_LoadImage("assets/text8x16.png");

    GPU_SetImageFilter(pctx->tilesImage, GPU_FILTER_NEAREST);
    GPU_SetImageFilter(pctx->textImage, GPU_FILTER_NEAREST);

    pctx->src = new GPU_Rect;
}

static void quitRender()
{
    GPU_FreeImage(pctx->tilesImage);
    GPU_FreeImage(pctx->textImage);
    GPU_Quit();
}

static void drawDebug(Context *ctx)
{
    blitText(format("%f", pctx->input.dt), 0, 0);
    blitText(
        format("%d %d", pctx->input.mouse.tile.x, pctx->input.mouse.tile.y),
        0,
        1);
    Tile *tile =
        map::tileAt(ctx, pctx->input.mouse.tile.x, pctx->input.mouse.tile.y);
    blitText(format("%d %d", tile->type, tile->variant), 0, 2);
}

static void drawTiles(Context *ctx, Vector2 offset, Rect bounds)
{
    int x1 = bounds.x;
    int y1 = bounds.y;
    int x2 = bounds.x + bounds.w;
    int y2 = bounds.y + bounds.h;

    TileData *tileData;

    for (int i = x1; i <= x2; i++) {
        for (int j = y1; j <= y2; j++) {
            tileData = map::tileDataAt(ctx, i, j);

            blitTileOffset(
                tileData->sprite.x,
                tileData->sprite.y,
                i,
                j,
                offset.x,
                offset.y,
                tileData->color);
        }
    }
}

static void drawEntities(Context *ctx, Vector2 offset, Rect bounds)
{
    for (Entity entity : ctx->entityPool.pool) {
        if (entity::has(ctx, &entity, PositionComponent | SpriteComponent)) {
            Position *pos = component::position(ctx, &entity);
            Sprite *spr = component::sprite(ctx, &entity);

            if (outside(bounds, pos->x, pos->y)) {
                continue;
            }

            blitRectOffset(
                pos->x,
                pos->y,
                tileWidth,
                tileHeight,
                offset.x - spr->ox * tileWidth * pctx->scale,
                offset.y - spr->oy * tileHeight * pctx->scale,
                backgroundColor);

            blitTileOffset(
                spr->x,
                spr->y,
                pos->x,
                pos->y,
                offset.x - spr->ox * tileWidth * pctx->scale,
                offset.y - spr->oy * tileHeight * pctx->scale,
                spr->color);
        }
    }
}

static void drawUI(Context *ctx)
{
    // blitText("Test string over here c'mon! WHAT's UP @", 0, 20);
}

static void beforeDraw()
{
    GPU_ClearColor(pctx->target, backgroundColor);
}

static void afterDraw()
{
    GPU_Flip(pctx->target);
}

static void draw(Context *ctx)
{
    beforeDraw();

    Vector2 offset = getCameraOffset(ctx);
    Rect bounds = getCameraTileBounds(ctx);
    drawTiles(ctx, offset, bounds);
    drawEntities(ctx, offset, bounds);
    drawUI(ctx);
    drawDebug(ctx);

    afterDraw();
}

} // namespace platform
