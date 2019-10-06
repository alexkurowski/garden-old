namespace game
{

static void init()
{
    ctx = new Context{0};
    if (!ctx) {
        throw runtime_error("Not enough memory");
    }

    systems::newGame(ctx);
}

static Context *update(Input &input)
{
    systems::playerInput(ctx, input);
    for (Entity entity : ctx->entityPool.pool) {
    }
    return ctx;
}

static void quit()
{
    delete ctx;
}

} // namespace game
