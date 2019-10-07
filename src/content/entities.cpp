namespace entity
{

static Entity *create(Context *ctx)
{
    EntityId id = ctx->entityPool.nextId;

    ctx->entityPool.nextId++;
    if (ctx->entityPool.nextId >= ENTITY_POOL) {
        ctx->entityPool.nextId = 0;
    }

    Entity *e = &ctx->entityPool.pool[id];
    e->id = id;
    e->components = 0;
    return e;
}

static bool has(Context *ctx, EntityId id, ComponentMask components)
{
    return (ctx->entityPool.pool[id].components & components) == components;
}

static bool has(Context *ctx, Entity *e, ComponentMask components)
{
    return (e->components & components) == components;
}

static Entity *get(Context *ctx, EntityId id)
{
    return &ctx->entityPool.pool[id];
}

static Entity *at(Context *ctx, int x, int y)
{
    Position *pos;
    for (Entity &e : ctx->entityPool.pool) {
        if (has(ctx, &e, PositionComponent)) {
            pos = component::position(ctx, &e);
            if (pos->x == x && pos->y == y) {
                return &e;
            }
        }
    }
    return nullptr;
}

static void destroy(Context *ctx, EntityId id)
{
    ctx->entityPool.pool[id].components = 0;
}

static void destroy(Context *ctx, Entity *e)
{
    e->components = 0;
}

static void add(Context *ctx, EntityId id, ComponentMask components)
{
    Entity *e = &ctx->entityPool.pool[id];
    e->components |= components;
}

static void add(Context *ctx, Entity *e, ComponentMask components)
{
    e->components |= components;
}

static void remove(Context *ctx, EntityId id, ComponentMask components)
{
    Entity *e = &ctx->entityPool.pool[id];
    e->components -= e->components & components;
}

static void remove(Context *ctx, Entity *e, ComponentMask components)
{
    e->components -= e->components & components;
}

} // namespace entity
