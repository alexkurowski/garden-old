struct Tile {
    TileType type;
    TileVariant variant;
};

struct Map {
    int seed;
    Tile blankTile = {TileType::Blank, 0};
    Tile tiles[MAP_WIDTH * MAP_HEIGHT];
};

struct Blueprint {
    int seed;
    TileType tiles[MAP_WIDTH * MAP_HEIGHT];
};
