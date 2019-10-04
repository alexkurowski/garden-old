struct Card {
    int x;            // Coordinates on the table
    int y;
    Vector3 position; // Mesh rendered position
    Vector3 target;   // Mesh movement target
};

struct Actor {
    string foo;
};

struct ComponentPool {
    Card card[ENTITY_POOL];
    Actor actor[ENTITY_POOL];
};

#define COMPONENT_TYPE(name) constexpr ComponentMask name ## Component

// clang-format off
COMPONENT_TYPE(Blank)       = 0;
COMPONENT_TYPE(Card)        = 1 << 0;
COMPONENT_TYPE(Known)       = 1 << 1;
COMPONENT_TYPE(Actor)       = 1 << 2;
COMPONENT_TYPE(Placeholder) = 1 << 3;
// clang-format on
