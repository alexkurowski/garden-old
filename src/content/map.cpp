namespace map
{

static bool isOutBounds(int x, int y)
{
    return x < 0 || y < 0 || x >= MAP_WIDTH || y >= MAP_HEIGHT;
}

static int at(int x, int y)
{
    return x + y * MAP_WIDTH;
}

static void generate(Context *ctx)
{
    Tile *tiles = ctx->map.tiles;
    for (int i = 0; i < MAP_WIDTH; i++) {
        for (int j = 0; j < MAP_HEIGHT; j++) {
            if (random(0, 8) == 0) {
                tiles[at(i, j)].type = TileType::Tree;
            } else {
                tiles[at(i, j)].type = TileType::Grass;
            }
        }
    }
}

static TileType typeAt(Context *ctx, int x, int y)
{
    if (isOutBounds(x, y)) {
        return TileType::Blank;
    }

    return ctx->map.tiles[at(x, y)].type;
}

} // namespace map
