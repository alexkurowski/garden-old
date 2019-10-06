namespace platform
{

static Vector2 getCameraOffset(Context *ctx)
{
    if (ctx->playerEntity != -1) {
        if (entity::has(ctx, ctx->playerEntity, PositionComponent)) {
            Position *position = component::position(ctx, ctx->playerEntity);
            float x = -pctx->windowWidth / 2 +
                position->x * tileWidth * pctx->scale +
                tileWidth * pctx->scale / 2;
            float y = -pctx->windowHeight / 2 +
                position->y * tileHeight * pctx->scale +
                tileHeight * pctx->scale / 2;
            return (Vector2){x, y};
        } else {
            return (Vector2){0, 0};
        }
    } else {
        return (Vector2){0, 0};
    }
}

} // namespace platform
