using Color = SDL_Color;

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
    GPU_Target *target;
    SDL_Window *window;
    GPU_Image *tilesImage;
    GPU_Image *textImage;
    GPU_Rect *src;

    SDL_Event event;

    bool running;
    int windowWidth;
    int windowHeight;
    int tilesWidth;
    int tilesHeight;
    int textWidth;
    int textHeight;
    float scale;
    Input input;
};

namespace platform
{
PlatformContext *pctx;
}
