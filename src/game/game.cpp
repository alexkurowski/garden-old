namespace game
{

static void init()
{
    ctx = new Context{0};
    systems::newGame(ctx);
}

static Context *update(Input &input)
{
    systems::dragndrop(ctx, input);
    for (Entity entity : ctx->entityPool.pool) {
        systems::move(ctx, &entity);
    }
    return ctx;
}

static void quit()
{
    delete ctx;
}

} // namespace game
