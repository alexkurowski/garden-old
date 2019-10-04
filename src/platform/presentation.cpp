namespace platform
{

static void setupPresentation()
{
    Image image = LoadImage("assets/card_with_text.png");
    ImageFlipVertical(&image);
    pctx->cardTexture = LoadTextureFromImage(image);
    UnloadImage(image);
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
        WHITE);

    DrawText(TextFormat("%d", pctx->input.mouse.wheel), 10, 50, 20, WHITE);

    DrawText(
        TextFormat("%d, %d", pctx->input.mouse.gridX, pctx->input.mouse.gridY),
        10,
        70,
        20,
        WHITE);
}

static void drawDebug3d()
{
    Vector3 pos = {pctx->input.mouse.tableX, 0, pctx->input.mouse.tableZ};
    DrawSphere(pos, 0.03f, MAROON);
}

static void drawEntities(Context *ctx)
{
    Vector3 pos;

    for (Entity entity : ctx->entityPool.pool) {
        if (entity.id == ctx->selectedEntity) {
            continue;
        }

        if (entity::has(ctx, &entity, CardComponent | KnownComponent)) {
            Vector3 &position = component::card(ctx, &entity)->position;
            pos.x = position.x * cardMarginWidth;
            pos.y = position.y + tableHeight;
            pos.z = position.z * cardMarginHeight;

            Color color = WHITE;
            if (entity.id == ctx->highlightedEntity) {
                color = GRAY;
            }

            DrawCubeTexture(
                pctx->cardTexture, pos, cardWidth, 0, cardHeight, color);
        }
    }

    if (ctx->selectedEntity != -1) {
        if (entity::has(
                ctx, ctx->selectedEntity, CardComponent | KnownComponent)) {
            Vector3 &position =
                component::card(ctx, ctx->selectedEntity)->position;
            pos.x = position.x * cardMarginWidth;
            pos.y = position.y + tableHeight;
            pos.z = position.z * cardMarginHeight;

            Color color = WHITE;
            if (ctx->highlightedEntity != -1) {
                color.a = 128;
            }

            DrawCubeTexture(
                pctx->cardTexture, pos, cardWidth, 0, cardHeight, color);
        }
    }
}

static void draw(Context *ctx)
{
    BeginDrawing();
    ClearBackground({10, 15, 20, 255});

    BeginMode3D(pctx->camera.camera);

    { // 3D
        DrawGrid(20, 1);
        drawEntities(ctx);

        drawDebug3d();
    }

    EndMode3D();

    { // 2D
        drawDebug(ctx);
    }

    EndDrawing();
}

} // namespace platform
