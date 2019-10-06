namespace platform
{

static void initRender()
{
    pctx->windowWidth = 800;
    pctx->windowHeight = 600;
    pctx->scale = 1.5f;
    pctx->tilesWidth = pctx->windowWidth / (tileWidth * pctx->scale);
    pctx->tilesHeight = pctx->windowHeight / (tileHeight * pctx->scale);
    pctx->textWidth = pctx->windowWidth / (charWidth * pctx->scale);
    pctx->textHeight = pctx->windowHeight / (charHeight * pctx->scale);

    SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_VSYNC_HINT);
    SetTargetFPS(60);
    InitWindow(pctx->windowWidth, pctx->windowHeight, "Garden");

    pctx->tilesTexture = LoadTexture("assets/tiles16x16.png");
    pctx->textTexture = LoadTexture("assets/text8x16.png");
}

static void quitRender()
{
    UnloadTexture(pctx->tilesTexture);
    UnloadTexture(pctx->textTexture);
    CloseWindow();
}

static void handleResize()
{
    pctx->windowWidth = GetScreenWidth();
    pctx->windowHeight = GetScreenHeight();
    pctx->tilesWidth = pctx->windowWidth / (tileWidth * pctx->scale);
    pctx->tilesHeight = pctx->windowHeight / (tileHeight * pctx->scale);
    pctx->textWidth = pctx->windowWidth / (charWidth * pctx->scale);
    pctx->textHeight = pctx->windowHeight / (charHeight * pctx->scale);
}

static void drawText(string str, int x, int y)
{
    Vector2 orig;
    const int line = 16;

    Rectangle src;
    Rectangle brd;
    Rectangle dst;
    int ox = 0;

    DrawRectangle(
        x * charWidth * pctx->scale,
        y * charHeight * pctx->scale,
        str.size() * charWidth * pctx->scale,
        1 * charHeight * pctx->scale,
        BLACK);

    for (char &ch : str) {
        src.x = ((int)ch % line) * charWidth;
        src.y = floor((int)ch / line) * charHeight;
        src.width = charWidth;
        src.height = charHeight;

        dst.x = (x + ox) * charWidth * pctx->scale;
        dst.y = y * charHeight * pctx->scale;
        dst.width = charWidth * pctx->scale;
        dst.height = charHeight * pctx->scale;

        DrawTexturePro(pctx->textTexture, src, dst, orig, 0, WHITE);

        ox++;
    }
}

static void drawDebug(Context *ctx)
{
    // DrawFPS(10, 10);

    DrawText(
        TextFormat(
            "%d %d", pctx->input.mouse.screenX, pctx->input.mouse.screenY),
        10,
        30,
        20,
        WHITE);

    DrawText(
        TextFormat("%d %d", pctx->input.mouse.tileX, pctx->input.mouse.tileY),
        10,
        50,
        20,
        WHITE);

    DrawText(
        TextFormat("%d %d", pctx->windowWidth, pctx->windowHeight),
        10,
        10,
        20,
        WHITE);
}

static void drawTiles(Context *ctx, Vector2 orig)
{
    Rectangle src;
    Rectangle dst;
    Rectangle fill = {8 * tileWidth, 5 * tileHeight, tileWidth, tileHeight};

    int x1 = orig.x / (tileWidth * pctx->scale);
    int y1 = orig.y / (tileHeight * pctx->scale);
    int x2 = x1 + pctx->tilesWidth;
    int y2 = y1 + pctx->tilesHeight;

    x1--;
    y1--;
    x2++;
    y2++;

    for (int i = x1; i < x2; i++) {
        for (int j = y1; j < y2; j++) {
            src.x = 5 * tileWidth;
            src.y = 0 * tileHeight;
            src.width = tileWidth;
            src.height = tileHeight;

            dst.x = i * tileWidth * pctx->scale;
            dst.y = j * tileHeight * pctx->scale;
            dst.width = tileWidth * pctx->scale;
            dst.height = tileHeight * pctx->scale;

            DrawTexturePro(pctx->tilesTexture, fill, dst, orig, 0, BLACK);
            DrawTexturePro(pctx->tilesTexture, src, dst, orig, 0, GREEN);
        }
    }
}

static void drawEntities(Context *ctx, Vector2 orig)
{
    Rectangle src;
    Rectangle dst;
    Rectangle fill = {8 * tileWidth, 5 * tileHeight, tileWidth, tileHeight};

    for (Entity entity : ctx->entityPool.pool) {
        if (entity::has(ctx, &entity, PositionComponent | TileComponent)) {
            Position *pos = component::position(ctx, &entity);
            Tile *tile = component::tile(ctx, &entity);

            src.x = tile->x * tileWidth;
            src.y = tile->y * tileHeight;
            src.width = tileWidth;
            src.height = tileHeight;

            dst.x = pos->x * tileWidth * pctx->scale;
            dst.y = pos->y * tileHeight * pctx->scale;
            dst.width = tileWidth * pctx->scale;
            dst.height = tileHeight * pctx->scale;

            DrawTexturePro(pctx->tilesTexture, fill, dst, orig, 0, BLACK);
            DrawTexturePro(pctx->tilesTexture, src, dst, orig, 0, WHITE);
        }
    }
}

static void drawUI(Context *ctx)
{
    drawText("Test string over here c'mon! WHAT's UP @", 0, 20);
}

static void draw(Context *ctx)
{
    if (IsWindowResized()) {
        handleResize();
    }

    BeginDrawing();
    ClearBackground({10, 15, 20, 255});

    { // 2D
        Vector2 offset = getCameraOffset(ctx);
        drawTiles(ctx, offset);
        drawEntities(ctx, offset);
        drawUI(ctx);
        drawDebug(ctx);
    }

    EndDrawing();
}

} // namespace platform
