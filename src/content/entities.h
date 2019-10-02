struct Entity {
    EntityId id = 0;
    ComponentMask components = 0;
};

struct EntityPool {
    EntityId nextId = 0;
    Entity pool[ENTITY_POOL];
};
