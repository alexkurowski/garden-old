namespace systems
{

static void playerInput(Context *ctx, Input &input)
{
    if (ctx->playerEntity != -1) {
        Entity *e = entity::get(ctx, ctx->playerEntity);
        Position *pos = component::position(ctx, e);

        switch (input.cmd) {
        case Command::GoN: {
            pos->y -= 1;
        } break;
        case Command::GoS: {
            pos->y += 1;
        } break;
        case Command::GoW: {
            pos->x -= 1;
        } break;
        case Command::GoE: {
            pos->x += 1;
        } break;
        case Command::GoNW: {
            pos->x -= 1;
            pos->y -= 1;
        } break;
        case Command::GoNE: {
            pos->x += 1;
            pos->y -= 1;
        } break;
        case Command::GoSW: {
            pos->x -= 1;
            pos->y += 1;
        } break;
        case Command::GoSE: {
            pos->x += 1;
            pos->y += 1;
        } break;
        default:
            break;
        }
    }
}

} // namespace systems
