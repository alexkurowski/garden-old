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

static void createFromBlueprint(Context *ctx)
{
    Tile *tile;

    ctx->map.seed = ctx->blueprint.seed;
    for (int i = 0; i < MAP_WIDTH; i++) {
        for (int j = 0; j < MAP_HEIGHT; j++) {
            tile = &ctx->map.tiles[at(i, j)];
            tile->type = ctx->blueprint.tiles[at(i, j)];
            tile->variant = random(0, tiles::data[tile->type].size() - 1);
        }
    }
}

static Tile *tileAt(Context *ctx, int x, int y)
{
    if (isOutBounds(x, y)) {
        return &ctx->map.blankTile;
    } else {
        return &ctx->map.tiles[at(x, y)];
    }
}

static TileData *tileDataAt(Context *ctx, int x, int y)
{
    Tile *tile;
    if (isOutBounds(x, y)) {
        tile = &ctx->map.blankTile;
    } else {
        tile = tileAt(ctx, x, y);
    }
    return &tiles::data[tile->type][tile->variant];
}

} // namespace map
