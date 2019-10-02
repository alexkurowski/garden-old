#define COMPONENT_GETTER(T, name)                                              \
    static T *name(EntityId id)                                                \
    {                                                                          \
        return &ctx->componentPool.name[id];                                   \
    }                                                                          \
    static T *name(Entity *e)                                                  \
    {                                                                          \
        return &ctx->componentPool.name[e->id];                                \
    }

namespace component
{

COMPONENT_GETTER(Position, position);
COMPONENT_GETTER(Actor, actor);

} // namespace component
