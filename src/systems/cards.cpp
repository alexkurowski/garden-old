namespace systems
{

constexpr float pickedCardHeight = 1.f;

static EntityId findEntityAt(Context *ctx, int x, int y)
{
    for (Entity e : ctx->entityPool.pool) {
        if (entity::has(ctx, &e, CardComponent | KnownComponent)) {
            Card *card = component::card(ctx, &e);
            if (card->x == x && card->y == y) {
                return e.id;
            }
        }
    }
    return -1;
}

static Card *findCardAt(Context *ctx, int x, int y, Card *excluded = nullptr)
{
    for (Entity e : ctx->entityPool.pool) {
        if (entity::has(ctx, &e, CardComponent | KnownComponent)) {
            Card *card = component::card(ctx, &e);
            if (card != excluded && card->x == x && card->y == y) {
                return card;
            }
        }
    }
    return nullptr;
}

static void dragndropRelease(Context *ctx, Input &input, Card *card)
{
    bool canPlace = true;

    // TODO: Find a card underneath and move it out (should be
    // done recursively)
    // If the card below is an action card, show the action dialog modal

    Card *anotherCard =
        findCardAt(ctx, input.mouse.gridX, input.mouse.gridY, card);
    if (anotherCard) {
        cout << "another card here" << endl;
        canPlace = false;
    }

    if (canPlace) {
        card->x = input.mouse.gridX;
        card->y = input.mouse.gridY;
    }

    card->target.x = card->x;
    card->target.y = 0;
    card->target.z = card->y;

    ctx->selectedEntity = -1;
    ctx->highlightedEntity = -1;
}

static void dragndropMove(Context *ctx, Input &input, Card *card)
{
    EntityId anotherEntity =
        findEntityAt(ctx, input.mouse.gridX, input.mouse.gridY);
    if (anotherEntity != ctx->selectedEntity) {
        ctx->highlightedEntity = anotherEntity;
    } else {
        ctx->highlightedEntity = -1;
    }

    card->target.x = input.mouse.tableScaledX;
    card->target.y = pickedCardHeight;
    card->target.z = input.mouse.tableScaledZ;
}

static void dragndropPick(Context *ctx, Input &input)
{
    EntityId id = findEntityAt(ctx, input.mouse.gridX, input.mouse.gridY);
    if (id != -1) {
        ctx->selectedEntity = id;
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
