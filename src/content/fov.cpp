namespace fov
{

static bool
isVisible(Context *ctx, int fromX, int fromY, int toX, int toY, float sight)
{
    int x0 = fromX;
    int y0 = fromY;
    int x1 = toX;
    int y1 = toY;

    float dx = x1 - x0;
    float dy = y1 - y0;
    float distance = sqrt(dx * dx + dy * dy);

    if (distance <= 1.5) {
        return true;
    }

    if (distance > sight) {
        return false;
    }

    // Calculate quadrant, we climg in these two directions
    float sx = x0 < x1 ? 1 : -1;
    float sy = y0 < y1 ? 1 : -1;

    int x = x0;
    int y = y0;

    while (x != x1 || y != y1) {
        if (!map::tileDataAt(ctx, x, y)->canSee) {
            return false;
        }

        // Climb
        if (abs(dy * (x - x0 + sx) - dx * (y - y0)) / distance < 0.5f) {
            x += sx;
        } else if (abs(dy * (x - x0) - dx * (y - y0 + sy)) / distance < 0.5f) {
            y += sy;
        } else {
            x += sx;
            y += sy;
        }
    }

    return true;
}

} // namespace fov
