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

struct Mouse {
    Point screen; // Coordinates on the screen
    Point tile;   // Coordinates on the tile grid, affected by camera position
    Point text;   // Coordinates on the ui text grid
    int btnPressed;
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
    Input input;

    bool running;
    int windowWidth; // Scaled screen pixels
    int windowHeight;
    int tilesWidth; // Tiles on screen
    int tilesHeight;
    int textWidth; // Text tiles on screen
    int textHeight;
    float scale;     // Total scale (os * game)
    float scaleDiff; // OS scale

    unsigned long int lastFrame;
    unsigned long int currentFrame;
};

namespace platform
{
PlatformContext *pctx;
}
