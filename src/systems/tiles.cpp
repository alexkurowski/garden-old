namespace systems
{

constexpr float tileAlphaEase = 0.1f;
constexpr int fullVisibility = 255; // Tile in sight
constexpr int halfVisibility = 64;  // Tile remembered
constexpr int noVisibility = 0;

static void updateTiles(Context *ctx)
{
    if (ctx->playerEntity != -1) {
        if (entity::has(ctx, ctx->playerEntity, PositionComponent)) {
            Position *pos = component::position(ctx, ctx->playerEntity);

            int x0 = pos->x - MAX_SIGHT * 2;
            int y0 = pos->y - MAX_SIGHT * 2;
            int x1 = pos->x + MAX_SIGHT * 2;
            int y1 = pos->y + MAX_SIGHT * 2;

            Tile *tile;
            int targetAlpha;
            float diff;

            for (int i = x0; i <= x1; i++) {
                for (int j = y0; j <= y1; j++) {
                    tile = map::tileAt(ctx, i, j);

                    if (tile->visible) {
                        targetAlpha = fullVisibility;
                    } else {
                        if (tile->alpha > 0) {
                            targetAlpha = halfVisibility;
                        } else {
                            targetAlpha = noVisibility;
                        }
                    }

                    diff = targetAlpha - tile->alpha;
                    tile->alpha = ceil(tile->alpha + diff * tileAlphaEase);
                }
            }
        }
    }
}

} // namespace systems
