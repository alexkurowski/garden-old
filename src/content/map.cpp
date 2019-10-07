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
            // TODO: this random needs to be deterministic, based on the seed
            // provided by the blueprint
            tile->variant = random(0, ctx->tileData[tile->type].size() - 1);
            tile->visible = false;
            tile->alpha = 0;
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

static TileData *getTileData(Context *ctx, Tile *tile)
{
    return &ctx->tileData[tile->type][tile->variant];
}

static TileData *tileDataAt(Context *ctx, int x, int y)
{
    return getTileData(ctx, tileAt(ctx, x, y));
}

} // namespace map
