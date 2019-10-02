namespace platform
{

static void init()
{
    pctx = new PlatformContext;

    pctx->windowWidth = 800;
    pctx->windowHeight = 600;

    InitWindow(pctx->windowWidth, pctx->windowHeight, "Garden");
    SetTargetFPS(60);
}

static void quit()
{
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
