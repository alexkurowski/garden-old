enum struct TileType {
    Blank,
    Grass,
    Tree,
};

struct Tile {
    TileType type;
};

struct Map {
    int seed;
    Tile tiles[MAP_WIDTH * MAP_HEIGHT];
};
