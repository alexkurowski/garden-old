struct Position {
    int x, y;
};

struct Actor {
    string foo;
};

struct ComponentPool {
    Position position[ENTITY_POOL];
    Actor actor[ENTITY_POOL];
};

// clang-format off
constexpr ComponentMask BlankComponent    = 0;
constexpr ComponentMask PositionComponent = 1 << 0;
constexpr ComponentMask ActorComponent    = 1 << 1;
constexpr ComponentMask FooComponent      = 1 << 2;
// clang-format on
