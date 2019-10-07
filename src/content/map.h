struct Tile {
    TileType type;
    TileVariant variant;
    bool visible;
    float alpha;
};

struct Map {
    int seed;
    Tile blankTile;
    Tile tiles[MAP_WIDTH * MAP_HEIGHT];
};

struct Blueprint {
    int seed;
    TileType tiles[MAP_WIDTH * MAP_HEIGHT];
};
