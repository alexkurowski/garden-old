namespace platform
{

static void init()
{
    pctx = new PlatformContext{0};
    if (!pctx) {
        throw runtime_error("Not enough memory");
    }

    initRender();
}

static void quit()
{
    quitRender();

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
