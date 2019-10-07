struct Context {
    ComponentPool componentPool;
    EntityPool entityPool;
    EntityId playerEntity = -1;
    TileDataMap tileData;
    Map map;
    Blueprint blueprint;
};

namespace game
{
Context *ctx;
}
