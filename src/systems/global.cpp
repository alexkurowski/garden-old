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

        Tile *tile = component::tile(ctx, e);
        tile->x = 27;
        tile->y = 0;

        entity::add(ctx, e, PositionComponent);
        entity::add(ctx, e, TileComponent);
    }

    {
        Entity *e = entity::create(ctx);

        Position *position = component::position(ctx, e);
        position->x = 1;
        position->y = 1;

        Tile *tile = component::tile(ctx, e);
        tile->x = 26;
        tile->y = 0;

        entity::add(ctx, e, PositionComponent);
        entity::add(ctx, e, TileComponent);
    }

    {
        Entity *e = entity::create(ctx);

        Position *position = component::position(ctx, e);
        position->x = 2;
        position->y = 2;

        Tile *tile = component::tile(ctx, e);
        tile->x = 25;
        tile->y = 0;

        entity::add(ctx, e, PositionComponent);
        entity::add(ctx, e, TileComponent);
    }
}

} // namespace systems
