namespace platform
{

static void init()
{
    pctx = new PlatformContext;

    pctx->windowWidth = 800;
    pctx->windowHeight = 600;

    setupCamera();

    SetConfigFlags(FLAG_MSAA_4X_HINT | FLAG_VSYNC_HINT);
    SetTargetFPS(60);
    InitWindow(pctx->windowWidth, pctx->windowHeight, "Garden");

    setupPresentation();
}

static void quit()
{
    UnloadTexture(pctx->cardTexture);
    CloseWindow();

    delete pctx;
}

static Context *update(Input &input)
{
    return game::update(input);
}

static void mainLoop()
{
    while (!WindowShouldClose()) {
        draw(update(input()));
    }
}

} // namespace platform
