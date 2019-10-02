namespace platform
{

static void draw(Context *ctx)
{
    BeginDrawing();

    ClearBackground(RAYWHITE);
    DrawText("Hello, World!", 10, 10, 20, BLACK);

    string mouse =
        to_string(pctx->input.mouseX) + " " + to_string(pctx->input.mouseY);
    DrawText(mouse.c_str(), 10, 40, 20, BLACK);

    EndDrawing();
}

} // namespace platform
