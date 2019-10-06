namespace platform
{

constexpr Color LIGHTGRAY = {200, 200, 200, 255};
constexpr Color GRAY = {130, 130, 130, 255};
constexpr Color DARKGRAY = {80, 80, 80, 255};
constexpr Color YELLOW = {253, 249, 0, 255};
constexpr Color GOLD = {255, 203, 0, 255};
constexpr Color ORANGE = {255, 161, 0, 255};
constexpr Color PINK = {255, 109, 194, 255};
constexpr Color RED = {230, 41, 55, 255};
constexpr Color MAROON = {190, 33, 55, 255};
constexpr Color GREEN = {0, 228, 48, 255};
constexpr Color LIME = {0, 158, 47, 255};
constexpr Color DARKGREEN = {0, 117, 44, 255};
constexpr Color SKYBLUE = {102, 191, 255, 255};
constexpr Color BLUE = {0, 121, 241, 255};
constexpr Color DARKBLUE = {0, 82, 172, 255};
constexpr Color PURPLE = {200, 122, 255, 255};
constexpr Color VIOLET = {135, 60, 190, 255};
constexpr Color DARKPURPLE = {112, 31, 126, 255};
constexpr Color BEIGE = {211, 176, 131, 255};
constexpr Color BROWN = {127, 106, 79, 255};
constexpr Color DARKBROWN = {76, 63, 47, 255};
constexpr Color WHITE = {255, 255, 255, 255};
constexpr Color BLACK = {0, 0, 0, 255};
constexpr Color BLANK = {0, 0, 0, 0};
constexpr Color MAGENTA = {255, 0, 255, 255};
constexpr Color RAYWHITE = {245, 245, 245, 255};

constexpr Color backgroundColor = {10, 15, 20, 255};

constexpr int initialWidth = 800;
constexpr int initialHeight = 600;
constexpr float initialScale = 1.5f;
constexpr int tileWidth = 16;
constexpr int tileHeight = 16;
constexpr int charWidth = 8;
constexpr int charHeight = 16;
constexpr int textLine = 16;

static void
blitTile(int srcX, int srcY, int dstX, int dstY, Color color = WHITE)
{
    GPU_SetColor(pctx->tilesImage, color);

    pctx->src->x = srcX * tileWidth;
    pctx->src->y = srcY * tileHeight;
    pctx->src->w = tileWidth;
    pctx->src->h = tileHeight;

    GPU_BlitScale(
        pctx->tilesImage,
        pctx->src,
        pctx->target,
        dstX * tileWidth * pctx->scale + tileWidth * pctx->scale / 2,
        dstY * tileHeight * pctx->scale + tileHeight * pctx->scale / 2,
        pctx->scale,
        pctx->scale);
}

static void blitTileOffset(
    int srcX,
    int srcY,
    int dstX,
    int dstY,
    int offsetX,
    int offsetY,
    Color color = WHITE)
{
    GPU_SetColor(pctx->tilesImage, color);

    pctx->src->x = srcX * tileWidth;
    pctx->src->y = srcY * tileHeight;
    pctx->src->w = tileWidth;
    pctx->src->h = tileHeight;

    GPU_BlitScale(
        pctx->tilesImage,
        pctx->src,
        pctx->target,
        dstX * tileWidth * pctx->scale + tileWidth * pctx->scale / 2 + offsetX,
        dstY * tileHeight * pctx->scale + tileHeight * pctx->scale / 2 +
            offsetY,
        pctx->scale,
        pctx->scale);
}

static void
blitRect(int dstX, int dstY, int width, int height, Color color = WHITE)
{
    float x1 = dstX * width * pctx->scale;
    float y1 = dstY * height * pctx->scale;
    float x2 = x1 + width * pctx->scale;
    float y2 = y1 + height * pctx->scale;
    GPU_RectangleFilled(pctx->target, x1, y1, x2, y2, color);
}

static void blitRectOffset(
    int dstX,
    int dstY,
    int width,
    int height,
    int offsetX,
    int offsetY,
    Color color = WHITE)
{
    float x1 = dstX * width * pctx->scale + offsetX;
    float y1 = dstY * height * pctx->scale + offsetY;
    float x2 = x1 + width * pctx->scale;
    float y2 = y1 + height * pctx->scale;
    GPU_RectangleFilled(pctx->target, x1, y1, x2, y2, color);
}

static void blitChar(char ch, int dstX, int dstY)
{
    pctx->src->x = ((int)ch % textLine) * charWidth;
    pctx->src->y = floor((int)ch / 16) * charHeight;
    pctx->src->w = charWidth;
    pctx->src->h = charHeight;

    GPU_BlitScale(
        pctx->textImage,
        pctx->src,
        pctx->target,
        dstX * charWidth * pctx->scale + charWidth * pctx->scale / 2,
        dstY * charHeight * pctx->scale + charHeight * pctx->scale / 2,
        pctx->scale,
        pctx->scale);
}

static void blitText(string str, int dstX, int dstY, Color color = WHITE)
{
    GPU_SetColor(pctx->textImage, color);

    // TODO: Draw background

    int offsetX = 0;

    for (char &ch : str) {
        blitRect(dstX + offsetX, dstY, charWidth, charHeight, backgroundColor);
        blitChar(ch, dstX + offsetX, dstY);
        offsetX++;
    }
}

static void
blitTextWrap(string str, int dstX, int dstY, int width, Color color = WHITE)
{
    GPU_SetColor(pctx->textImage, color);

    // TODO: Draw background

    int offsetX = 0;
    int offsetY = 0;

    for (char &ch : str) {
        blitChar(ch, dstX + offsetX, dstY + offsetY);
        offsetX++;

        if (offsetX > width) {
            offsetX = 0;
            offsetY++;
        }
    }
}

} // namespace platform
