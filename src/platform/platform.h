constexpr int tileWidth = 16;
constexpr int tileHeight = 16;

enum struct Command {
    None,
    GoN,
    GoS,
    GoW,
    GoE,
    GoNW,
    GoNE,
    GoSW,
    GoSE,
};

struct Keyboard {
    bool shift;
    bool ctrl;
    bool alt;
    char keyPressed;
};

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
    Command cmd;
    Keyboard keyboard;
    Mouse mouse;
};

struct PlatformContext {
    int windowWidth;
    int windowHeight;
    int tilesWidth;
    int tilesHeight;
    float scale;
    Input input;
    Texture2D tilesTexture;
};

namespace platform
{
PlatformContext *pctx;
}
