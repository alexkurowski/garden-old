namespace systems
{

constexpr float spriteEase = 0.875f;

static void moveSprite(Context *ctx, Entity *e, float dt)
{
    if (entity::has(ctx, e, SpriteComponent)) {
        Sprite *spr = component::sprite(ctx, e);

        if (spr->ox != 0 || spr->oy != 0) {
            // TODO: use dt for smoother smoothing
            spr->ox *= spriteEase;
            spr->oy *= spriteEase;
        }
    }
}

} // namespace systems
