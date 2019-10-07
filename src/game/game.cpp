namespace game
{

static void init()
{
    ctx = new Context{0};
    if (!ctx) {
        throw runtime_error("Not enough memory");
    }

    tiles::initData();
    blueprints::generateTest(ctx);
    map::createFromBlueprint(ctx);
    systems::newGame(ctx);
}

static Context *update(Input &input)
{
    systems::playerInput(ctx, input);
    for (Entity entity : ctx->entityPool.pool) {
        systems::moveSprite(ctx, &entity, input.dt);
    }
    return ctx;
}

static void quit()
{
    delete ctx;
}

} // namespace game
