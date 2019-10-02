namespace platform
{

void init()
{
    pctx = new PlatformContext;

    pctx->windowWidth = 800;
    pctx->windowHeight = 600;

    InitWindow(pctx->windowWidth, pctx->windowHeight, "Garden");
    SetTargetFPS(60);
}

void quit()
{
    CloseWindow();

    delete pctx;
}

Context *update(Input &input)
{
    return game::update(input);
}

void mainLoop()
{
    while (!WindowShouldClose()) {
        draw(update(input()));
    }
}

} // namespace platform
