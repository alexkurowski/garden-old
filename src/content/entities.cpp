namespace entity
{

static Entity *create()
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

static Entity *get(EntityId id)
{
    return &ctx->entityPool.pool[id];
}

static void destroy(EntityId id)
{
    ctx->entityPool.pool[id].components = 0;
}

static void destroy(Entity *e)
{
    e->components = 0;
}

static void add(EntityId id, ComponentMask components)
{
    Entity *e = &ctx->entityPool.pool[id];
    e->components |= components;
}

static void add(Entity *e, ComponentMask components)
{
    e->components |= components;
}

static bool has(EntityId id, ComponentMask components)
{
    return (ctx->entityPool.pool[id].components & components) == components;
}

static bool has(Entity *e, ComponentMask components)
{
    return (e->components & components) == components;
}

static void remove(EntityId id, ComponentMask components)
{
    Entity *e = &ctx->entityPool.pool[id];
    e->components -= e->components & components;
}

static void remove(Entity *e, ComponentMask components)
{
    e->components -= e->components & components;
}

} // namespace entity
