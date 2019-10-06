namespace platform
{

static void handleResize(int w, int h)
{
    GPU_SetWindowResolution(w, h);

    int glWidth, glHeight;
    int sdlWidth, sdlHeight;
    SDL_GL_GetDrawableSize(pctx->window, &glWidth, &glHeight);
    SDL_GetWindowSize(pctx->window, &sdlWidth, &sdlHeight);

    pctx->scale = initialScale * glWidth / sdlWidth;
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
    blitText(format("%d %d", pctx->windowWidth, pctx->windowHeight), 0, 0);

    // DrawFPS(10, 10);

    // DrawText(
    //     TextFormat(
    //         "%d %d", pctx->input.mouse.screenX, pctx->input.mouse.screenY),
    //     10,
    //     30,
    //     20,
    //     WHITE);

    // DrawText(
    //     TextFormat("%d %d", pctx->input.mouse.tileX,
    //     pctx->input.mouse.tileY), 10, 50, 20, WHITE);

    // DrawText(
    //     TextFormat("%d %d", pctx->windowWidth, pctx->windowHeight),
    //     10,
    //     10,
    //     20,
    //     WHITE);
}

static void drawTiles(Context *ctx, Vector2 orig)
{
    // Rectangle src;
    // Rectangle dst;
    // Rectangle fill = {8 * tileWidth, 5 * tileHeight, tileWidth, tileHeight};

    // int x1 = orig.x / (tileWidth * pctx->scale);
    // int y1 = orig.y / (tileHeight * pctx->scale);
    // int x2 = x1 + pctx->tilesWidth;
    // int y2 = y1 + pctx->tilesHeight;

    // x1--;
    // y1--;
    // x2++;
    // y2++;

    // for (int i = x1; i < x2; i++) {
    //     for (int j = y1; j < y2; j++) {
    //         src.x = 5 * tileWidth;
    //         src.y = 0 * tileHeight;
    //         src.width = tileWidth;
    //         src.height = tileHeight;

    //         dst.x = i * tileWidth * pctx->scale;
    //         dst.y = j * tileHeight * pctx->scale;
    //         dst.width = tileWidth * pctx->scale;
    //         dst.height = tileHeight * pctx->scale;

    //         DrawTexturePro(pctx->tilesImage, fill, dst, orig, 0, BLACK);
    //         DrawTexturePro(pctx->tilesImage, src, dst, orig, 0, GREEN);
    //     }
    // }
}

static void drawEntities(Context *ctx, Vector2 offset)
{
    for (Entity entity : ctx->entityPool.pool) {
        if (entity::has(ctx, &entity, PositionComponent | TileComponent)) {
            Position *pos = component::position(ctx, &entity);
            Tile *tile = component::tile(ctx, &entity);

            blitTileOffset(
                tile->x, tile->y, pos->x, pos->y, offset.x, offset.y, WHITE);

            // src.x = tile->x * tileWidth;
            // src.y = tile->y * tileHeight;
            // src.width = tileWidth;
            // src.height = tileHeight;

            // dst.x = pos->x * tileWidth * pctx->scale;
            // dst.y = pos->y * tileHeight * pctx->scale;
            // dst.width = tileWidth * pctx->scale;
            // dst.height = tileHeight * pctx->scale;

            // DrawTexturePro(pctx->tilesImage, fill, dst, orig, 0, BLACK);
            // DrawTexturePro(pctx->tilesImage, src, dst, orig, 0, WHITE);
        }
    }
}

static void drawUI(Context *ctx)
{
    // drawText("Test string over here c'mon! WHAT's UP @", 0, 20);
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

    { // 2D
        Vector2 offset = getCameraOffset(ctx);
        drawTiles(ctx, offset);
        drawEntities(ctx, offset);
        drawUI(ctx);
        drawDebug(ctx);
    }

    afterDraw();
}

} // namespace platform
