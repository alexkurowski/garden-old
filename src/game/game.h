struct Context {
    ComponentPool componentPool;
    EntityPool entityPool;
    EntityId playerEntity = -1;
    EntityId selectedEntity = -1;
};

namespace game
{
Context *ctx;
}
