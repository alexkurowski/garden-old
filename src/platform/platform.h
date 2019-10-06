constexpr int tileWidth = 16;
constexpr int tileHeight = 16;
constexpr float scale = 2;

enum struct MouseButtonState {
    Up,
    Pressed,
    Down,
    Released,
};

struct Mouse {
    int screenX; // Coordinates on the screen
    int screenY;
    int tileX; // Coordinates on the scaled grid
    int tileY;
    MouseButtonState left;
    MouseButtonState right;
};

struct Input {
    float dt;
    Mouse mouse;
};

struct PlatformContext {
    int windowWidth;
    int windowHeight;
    int tilesWidth;
    int tilesHeight;
    Input input;
    Texture2D tilesTexture;
};

namespace platform
{
PlatformContext *pctx;
}
