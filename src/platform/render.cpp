namespace platform
{

static void handleResize(int w, int h)
{
    GPU_SetWindowResolution(w, h);

    int glWidth, glHeight;   // Actual pixels
    int sdlWidth, sdlHeight; // Pixels scaled by OS
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

static void drawText(string str, int x, int y)
{
    // Vector2 orig;
    // const int line = 16;

    // Rectangle src;
    // Rectangle brd;
    // Rectangle dst;
    // int ox = 0;

    // DrawRectangle(
    //     x * charWidth * pctx->scale,
    //     y * charHeight * pctx->scale,
    //     str.size() * charWidth * pctx->scale,
    //     1 * charHeight * pctx->scale,
    //     BLACK);

    // for (char &ch : str) {
    //     src.x = ((int)ch % line) * charWidth;
    //     src.y = floor((int)ch / line) * charHeight;
    //     src.width = charWidth;
    //     src.height = charHeight;

    //     dst.x = (x + ox) * charWidth * pctx->scale;
    //     dst.y = y * charHeight * pctx->scale;
    //     dst.width = charWidth * pctx->scale;
    //     dst.height = charHeight * pctx->scale;

    //     DrawTexturePro(pctx->textImage, src, dst, orig, 0, WHITE);

    //     ox++;
    // }
}

static void drawDebug(Context *ctx)
{
    blitText(format("%f", pctx->input.dt), 0, 0);
    blitText(
        format("%d %d", pctx->input.mouse.screen.x, pctx->input.mouse.screen.y),
        0,
        1);
    blitText(
        format("%d %d", pctx->input.mouse.tile.x, pctx->input.mouse.tile.y),
        0,
        2);
    blitText(format("%d", pctx->input.keyboard.keyPressed), 0, 3);
    blitText(format("%d", pctx->input.mouse.btnPressed), 0, 4);
}

static void drawTiles(Context *ctx, Vector2 offset)
{
    int x1 = -offset.x / (tileWidth * pctx->scale);
    int y1 = -offset.y / (tileHeight * pctx->scale);
    int x2 = x1 + pctx->tilesWidth;
    int y2 = y1 + pctx->tilesHeight;

    x1--;
    y1--;
    x2++;
    y2++;

    for (int i = x1; i <= x2; i++) {
        for (int j = y1; j <= y2; j++) {
            blitTileOffset(5, 0, i, j, offset.x, offset.y, GREEN);
        }
    }
}

static void drawEntities(Context *ctx, Vector2 offset)
{
    for (Entity entity : ctx->entityPool.pool) {
        if (entity::has(ctx, &entity, PositionComponent | TileComponent)) {
            Position *pos = component::position(ctx, &entity);
            Tile *tile = component::tile(ctx, &entity);

            blitRectOffset(
                pos->x,
                pos->y,
                tileWidth,
                tileHeight,
                offset.x,
                offset.y,
                backgroundColor);

            blitTileOffset(
                tile->x, tile->y, pos->x, pos->y, offset.x, offset.y, WHITE);
        }
    }
}

static void drawUI(Context *ctx)
{
    blitText("Test string over here c'mon! WHAT's UP @", 0, 20);
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
    drawTiles(ctx, offset);
    drawEntities(ctx, offset);
    drawUI(ctx);
    drawDebug(ctx);

    afterDraw();
}

} // namespace platform
