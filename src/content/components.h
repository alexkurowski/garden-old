struct Position {
    int x;
    int y;
};

struct Tile {
    int x;
    int y;
};

struct Actor {
    string foo;
};

struct ComponentPool {
    Position position[ENTITY_POOL];
    Tile tile[ENTITY_POOL];
    Actor actor[ENTITY_POOL];
};

#define COMPONENT_TYPE(name) constexpr ComponentMask name##Component

// clang-format off
COMPONENT_TYPE(Blank)       = 0;
COMPONENT_TYPE(Position)    = 1 << 0;
COMPONENT_TYPE(Tile)        = 1 << 1;
COMPONENT_TYPE(Actor)       = 1 << 2;
COMPONENT_TYPE(Placeholder) = 1 << 3;
// clang-format on
