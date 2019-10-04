namespace platform
{

static void drawDebug(Context *ctx)
{
    DrawText(
        TextFormat(
            "%d %d", pctx->input.mouse.screenX, pctx->input.mouse.screenY),
        10,
        40,
        20,
        BLACK);

    DrawText(TextFormat("%d", pctx->input.mouse.wheel), 10, 60, 20, BLACK);

    DrawRectangleLines(10, 100, 60, 10, BLACK);

    if (pctx->input.mouse.left == MouseButtonState::Pressed) {
        DrawRectangle(10, 100, 10, 10, MAROON);
    }
    if (pctx->input.mouse.left == MouseButtonState::Released) {
        DrawRectangle(20, 100, 10, 10, MAROON);
    }
    if (pctx->input.mouse.left == MouseButtonState::Down) {
        DrawRectangle(30, 100, 10, 10, MAROON);
    }

    if (pctx->input.mouse.right == MouseButtonState::Pressed) {
        DrawRectangle(40, 100, 10, 10, PURPLE);
    }
    if (pctx->input.mouse.right == MouseButtonState::Released) {
        DrawRectangle(50, 100, 10, 10, PURPLE);
    }
    if (pctx->input.mouse.right == MouseButtonState::Down) {
        DrawRectangle(60, 100, 10, 10, PURPLE);
    }

    DrawText(
        TextFormat("%d, %d", pctx->input.mouse.gridX, pctx->input.mouse.gridY),
        10,
        200,
        20,
        BLACK);

    DrawFPS(10, 10);
}

static void drawDebug3d()
{
    Vector3 pos = {pctx->input.mouse.tableX, 0, pctx->input.mouse.tableZ};
    DrawSphere(pos, 0.2f, MAROON);
}

static void drawEntities(Context *ctx)
{
    Vector3 pos;

    for (Entity entity : ctx->entityPool.pool) {
        if (entity::has(ctx, &entity, CardComponent | KnownComponent)) {
            Vector3 &position = component::card(ctx, &entity)->position;
            pos.x = position.x * cardMarginWidth;
            pos.y = position.y + tableHeight;
            pos.z = position.z * cardMarginHeight;
            DrawCube(pos, cardWidth, 0, cardHeight, DARKBLUE);
        }
    }
}

static void draw(Context *ctx)
{
    BeginDrawing();
    ClearBackground(RAYWHITE);

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
