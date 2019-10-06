namespace platform
{

static void init()
{
    pctx = new PlatformContext{0};
    if (!pctx) {
        throw runtime_error("Not enough memory");
    }

    pctx->windowWidth = 800;
    pctx->windowHeight = 600;
    pctx->scale = 1.5f;
    pctx->tilesWidth = pctx->windowWidth / (tileWidth * pctx->scale);
    pctx->tilesHeight = pctx->windowHeight / (tileHeight * pctx->scale);
    pctx->textWidth = pctx->windowWidth / (charWidth * pctx->scale);
    pctx->textHeight = pctx->windowHeight / (charHeight * pctx->scale);

    SetConfigFlags(FLAG_VSYNC_HINT);
    SetTargetFPS(60);
    InitWindow(pctx->windowWidth, pctx->windowHeight, "Garden");

    setupPresentation();
}

static void quit()
{
    UnloadTexture(pctx->tilesTexture);
    UnloadTexture(pctx->textTexture);
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
        draw(update(input(game::ctx)));
    }
}

} // namespace platform
