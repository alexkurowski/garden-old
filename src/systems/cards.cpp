namespace systems
{

constexpr float pickedCardHeight = 1.f;

static void dragndropRelease(Context *ctx, Input &input, Card *card)
{
    ctx->selectedEntity = -1;
    card->x = input.mouse.gridX;
    card->y = input.mouse.gridY;
    card->target.x = card->x;
    card->target.y = 0;
    card->target.z = card->y;
    // TODO: Find a card underneath and move it out (should be
    // done recursively)
}

static void dragndropMove(Context *ctx, Input &input, Card *card)
{
    card->target.x = input.mouse.tableScaledX;
    card->target.y = pickedCardHeight;
    card->target.z = input.mouse.tableScaledZ;
}

static void dragndropPick(Context *ctx, Input &input)
{
    for (Entity e : ctx->entityPool.pool) {
        if (entity::has(ctx, &e, CardComponent | KnownComponent)) {
            Card *card = component::card(ctx, &e);
            if (card->x == input.mouse.gridX && card->y == input.mouse.gridY) {
                ctx->selectedEntity = e.id;
                return;
            }
        }
    }
}

static void dragndrop(Context *ctx, Input &input)
{
    if (ctx->selectedEntity != -1) {
        Card *card = component::card(ctx, ctx->selectedEntity);

        if (input.mouse.left == MouseButtonState::Released) {
            dragndropRelease(ctx, input, card);
        } else {
            dragndropMove(ctx, input, card);
        }
    } else {
        if (input.mouse.left == MouseButtonState::Pressed) {
            dragndropPick(ctx, input);
        }
    }
}

constexpr float cardEase = 0.1f;

static void move(Context *ctx, Entity *e)
{
    if (entity::has(ctx, e, CardComponent)) {
        Card *card = component::card(ctx, e);
        card->position.x += (card->target.x - card->position.x) * cardEase;
        card->position.y += (card->target.y - card->position.y) * cardEase;
        card->position.z += (card->target.z - card->position.z) * cardEase;
    }
}

} // namespace systems
