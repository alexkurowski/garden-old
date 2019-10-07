namespace systems
{

static void recalculateFov(Context *ctx)
{
    if (ctx->playerEntity != -1) {
        if (entity::has(
                ctx, ctx->playerEntity, PositionComponent | SightComponent)) {
            Position *pos = component::position(ctx, ctx->playerEntity);
            Sight *sight = component::sight(ctx, ctx->playerEntity);

            float radius = fmin(sight->radius, MAX_SIGHT);
            int x0 = pos->x - radius - 1;
            int y0 = pos->y - radius - 1;
            int x1 = pos->x + radius + 1;
            int y1 = pos->y + radius + 1;

            Tile *tile;

            for (int i = x0; i <= x1; i++) {
                for (int j = y0; j <= y1; j++) {
                    tile = map::tileAt(ctx, i, j);
                    tile->visible =
                        fov::isVisible(ctx, pos->x, pos->y, i, j, radius);
                }
            }
        }
    }
}

} // namespace systems
