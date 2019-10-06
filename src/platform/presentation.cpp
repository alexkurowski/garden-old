namespace platform
{

static void setupPresentation()
{
    pctx->tilesTexture = LoadTexture("assets/tiles16.png");
}

static void drawDebug(Context *ctx)
{
    DrawFPS(10, 10);

    DrawText(
        TextFormat(
            "%d %d", pctx->input.mouse.screenX, pctx->input.mouse.screenY),
        10,
        30,
        20,
        RED);

    DrawText(
        TextFormat("%d %d", pctx->input.mouse.tileX, pctx->input.mouse.tileY),
        10,
        50,
        20,
        RED);

    DrawText(
        TextFormat("%d", pctx->input.keyboard.keyPressed), 10, 70, 20, GREEN);
}

static void drawEntities(Context *ctx)
{
    Vector2 orig;
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

static void draw(Context *ctx)
{
    BeginDrawing();
    ClearBackground({10, 15, 20, 255});

    { // 2D
        drawEntities(ctx);
        drawDebug(ctx);
    }

    EndDrawing();
}

} // namespace platform
