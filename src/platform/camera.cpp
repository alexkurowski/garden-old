namespace platform
{

static Vector2 getCameraOffset(Context *ctx)
{
    if (ctx->playerEntity != -1) {
        if (entity::has(
                ctx, ctx->playerEntity, PositionComponent | SpriteComponent)) {
            Position *position = component::position(ctx, ctx->playerEntity);
            Sprite *sprite = component::sprite(ctx, ctx->playerEntity);
            float x = -pctx->windowWidth / 2 +
                position->x * tileWidth * pctx->scale +
                tileWidth * pctx->scale / 2 -
                sprite->ox * tileWidth * pctx->scale;
            float y = -pctx->windowHeight / 2 +
                position->y * tileHeight * pctx->scale +
                tileHeight * pctx->scale / 2 -
                sprite->oy * tileHeight * pctx->scale;
            return Vector2{-x, -y};

        } else if (entity::has(ctx, ctx->playerEntity, PositionComponent)) {
            Position *position = component::position(ctx, ctx->playerEntity);
            float x = -pctx->windowWidth / 2 +
                position->x * tileWidth * pctx->scale +
                tileWidth * pctx->scale / 2;
            float y = -pctx->windowHeight / 2 +
                position->y * tileHeight * pctx->scale +
                tileHeight * pctx->scale / 2;
            return Vector2{-x, -y};

        } else {
            return Vector2{0, 0};
        }
    } else {
        return Vector2{0, 0};
    }
}

static Rect getCameraTileBounds(Context *ctx)
{
    Rect result;
    Vector2 offset = getCameraOffset(ctx);
    result.x = -offset.x / (tileWidth * pctx->scale) - 1;
    result.y = -offset.y / (tileHeight * pctx->scale) - 1;
    result.w = pctx->tilesWidth + 2;
    result.h = pctx->tilesHeight + 2;
    return result;
}

} // namespace platform
