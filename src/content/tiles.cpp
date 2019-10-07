namespace tiles
{

static void initData(Context *ctx)
{
    ctx->map.blankTile = {TileType::Blank, 0, false, 0};

    // clang-format off
    ctx->tileData = {
        {
            TileType::Blank,
            {
                {{0, 0}, BLANK, CANT_SEE, CANT_WALK},
            }
        },
        {
            TileType::Grass,
            {
                {{1, 0}, GREEN,     CAN_SEE, CAN_WALK},
                {{1, 0}, DARKGREEN, CAN_SEE, CAN_WALK},
                {{5, 0}, GREEN,     CAN_SEE, CAN_WALK},
                {{5, 0}, DARKGREEN, CAN_SEE, CAN_WALK},
                {{6, 0}, GREEN,     CAN_SEE, CAN_WALK},
                {{6, 0}, DARKGREEN, CAN_SEE, CAN_WALK},
            }
        },
        {
            TileType::Tree,
            {
                {{0, 1}, GREEN,     CANT_SEE, CANT_WALK},
                {{0, 1}, DARKGREEN, CANT_SEE, CANT_WALK},
                {{1, 1}, GREEN,     CANT_SEE, CANT_WALK},
                {{1, 1}, DARKGREEN, CANT_SEE, CANT_WALK},
                {{2, 1}, GREEN,     CANT_SEE, CANT_WALK},
                {{2, 1}, DARKGREEN, CANT_SEE, CANT_WALK},
                {{3, 1}, GREEN,     CANT_SEE, CANT_WALK},
                {{3, 1}, DARKGREEN, CANT_SEE, CANT_WALK},
                {{4, 1}, GREEN,     CANT_SEE, CANT_WALK},
                {{4, 1}, DARKGREEN, CANT_SEE, CANT_WALK},
            }
        },
    };
    // clang-format on
}

} // namespace tiles
