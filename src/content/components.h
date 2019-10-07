struct Position {
    int x;
    int y;
};

struct Sight {
    float radius;
};

struct Sprite {
    int x; // Coordinates on the image
    int y;
    float ox; // Offset added to the blit
    float oy;
    Color color;
};

struct Actor {
    string foo;
};

struct ComponentPool {
    Position position[ENTITY_POOL];
    Sight sight[ENTITY_POOL];
    Sprite sprite[ENTITY_POOL];
    Actor actor[ENTITY_POOL];
};

#define COMPONENT_TYPE(name) constexpr ComponentMask name##Component

// clang-format off
COMPONENT_TYPE(Blank)       = 0;
COMPONENT_TYPE(Position)    = 1 << 0;
COMPONENT_TYPE(Sight)       = 1 << 1;
COMPONENT_TYPE(Sprite)      = 1 << 2;
COMPONENT_TYPE(Actor)       = 1 << 3;
COMPONENT_TYPE(Placeholder) = 1 << 4;
// clang-format on
