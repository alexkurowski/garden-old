struct Context {
    ComponentPool componentPool;
    EntityPool entityPool;
    EntityId playerEntity = -1;
    Map map;
};

namespace game
{
Context *ctx;
}
