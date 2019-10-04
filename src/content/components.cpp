#define COMPONENT_GETTER(T, name)                                              \
    static T *name(Context *ctx, EntityId id)                                  \
    {                                                                          \
        return &ctx->componentPool.name[id];                                   \
    }                                                                          \
    static T *name(Context *ctx, Entity *e)                                    \
    {                                                                          \
        return &ctx->componentPool.name[e->id];                                \
    }

namespace component
{

COMPONENT_GETTER(Card, card);
COMPONENT_GETTER(Actor, actor);

} // namespace component