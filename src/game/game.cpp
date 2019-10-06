namespace game
{

static void init()
{
    ctx = new Context{0};
    systems::newGame(ctx);
}

static Context *update(Input &input)
{
    for (Entity entity : ctx->entityPool.pool) {
    }
    return ctx;
}

static void quit()
{
    delete ctx;
}

} // namespace game
