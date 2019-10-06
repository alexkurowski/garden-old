enum struct TileType {
    Blank,
    Grass,
    Tree,
};

struct Tile {
    TileType type;
};

struct Map {
    Tile tiles[MAP_WIDTH * MAP_HEIGHT];
};
