namespace systems
{

static void newGame(Context *ctx)
{
    // Loading a json file example:
    // json deck = json::parse(LoadText("assets/deck.json"));
    // string foo = deck["deck"][0]["foo"];
    // cout << foo << endl;

    {
        Entity *e = entity::create(ctx);

        Position *position = component::position(ctx, e);
        position->x = 0;
        position->y = 0;

        Sprite *sprite = component::sprite(ctx, e);
        sprite->x = 27;
        sprite->y = 0;
        sprite->color = RED;

        entity::add(ctx, e, PositionComponent);
        entity::add(ctx, e, SpriteComponent);
    }

    {
        Entity *e = entity::create(ctx);

        Position *position = component::position(ctx, e);
        position->x = 1;
        position->y = 1;

        Sprite *sprite = component::sprite(ctx, e);
        sprite->x = 26;
        sprite->y = 0;
        sprite->color = BLUE;

        entity::add(ctx, e, PositionComponent);
        entity::add(ctx, e, SpriteComponent);
    }

    {
        Entity *e = entity::create(ctx);

        Position *position = component::position(ctx, e);
        position->x = 2;
        position->y = 2;

        Sight *sight = component::sight(ctx, e);
        sight->radius = 12;

        Sprite *sprite = component::sprite(ctx, e);
        sprite->x = 25;
        sprite->y = 0;
        sprite->color = WHITE;

        entity::add(ctx, e, PositionComponent);
        entity::add(ctx, e, SightComponent);
        entity::add(ctx, e, SpriteComponent);
        ctx->playerEntity = e->id;
        recalculateFov(ctx);
    }
}

} // namespace systems
