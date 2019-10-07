namespace blueprints
{

static int at(int x, int y)
{
    return x + y * MAP_WIDTH;
}

static void generateTest(Context *ctx)
{
    Blueprint &b = ctx->blueprint;

    b.seed = random(0, 1000);
    for (int i = 0; i < MAP_WIDTH; i++) {
        for (int j = 0; j < MAP_HEIGHT; j++) {
            if (noiseAt(i * 0.1, j * 0.1, b.seed) < 0.3) {
                b.tiles[at(i, j)] = TileType::Tree;
            } else {
                b.tiles[at(i, j)] = TileType::Grass;
            }
        }
    }
}

} // namespace blueprints
