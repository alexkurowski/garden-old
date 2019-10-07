namespace systems
{

static void playerInput(Context *ctx, Input &input)
{
    if (input.keyboard.keyPressed == 'r') {
        blueprints::generateTest(ctx);
        map::createFromBlueprint(ctx);
        recalculateFov(ctx);
    }

    if (ctx->playerEntity != -1) {
        Entity *e = entity::get(ctx, ctx->playerEntity);
        Position *pos = component::position(ctx, e);

        int dx = 0;
        int dy = 0;

        switch (input.cmd) {
        case Command::GoN: {
            dy--;
        } break;
        case Command::GoS: {
            dy++;
        } break;
        case Command::GoW: {
            dx--;
        } break;
        case Command::GoE: {
            dx++;
        } break;
        case Command::GoNW: {
            dx--;
            dy--;
        } break;
        case Command::GoNE: {
            dx++;
            dy--;
        } break;
        case Command::GoSW: {
            dx--;
            dy++;
        } break;
        case Command::GoSE: {
            dx++;
            dy++;
        } break;
        default:
            break;
        }

        if (dx != 0 || dy != 0) {
            pos->x += dx;
            pos->y += dy;

            if (entity::has(ctx, e, SpriteComponent)) {
                Sprite *spr = component::sprite(ctx, e);
                spr->ox += dx;
                spr->oy += dy;

                if (abs(spr->ox) < 0.01f) {
                    spr->ox = 0;
                }
                if (abs(spr->oy) < 0.01f) {
                    spr->oy = 0;
                }
            }

            recalculateFov(ctx);
        }
    }
}

} // namespace systems
