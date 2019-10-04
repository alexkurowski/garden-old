namespace systems
{

static void moveImmediately(Card *card)
{
    card->position.x = card->target.x = card->x;
    card->position.y = card->target.y = 0;
    card->position.z = card->target.z = card->y;
}

static void newGame(Context *ctx)
{
    json test = json::parse(LoadText("assets/test.json"));
    string foo = test["cards"][0]["foo"];
    cout << foo << endl;

    {
        Entity *e = entity::create(ctx);

        Card *card = component::card(ctx, e->id);
        card->x = 0;
        card->y = 0;
        moveImmediately(card);
        entity::add(ctx, e, CardComponent);
        entity::add(ctx, e, KnownComponent);
    }

    {
        Entity *e = entity::create(ctx);

        Card *card = component::card(ctx, e->id);
        card->x = 1;
        card->y = 0;
        moveImmediately(card);
        entity::add(ctx, e, CardComponent);
        entity::add(ctx, e, KnownComponent);
    }

    {
        Entity *e = entity::create(ctx);

        Card *card = component::card(ctx, e->id);
        card->x = 0;
        card->y = 1;
        moveImmediately(card);
        entity::add(ctx, e, CardComponent);
        entity::add(ctx, e, KnownComponent);
    }
}

} // namespace systems
