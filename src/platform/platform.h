constexpr float cardMargin = 0.1f;
constexpr float cardWidth = 0.9f;
constexpr float cardHeight = 1.5f;
constexpr float cardMarginWidth = cardWidth + cardMargin;
constexpr float cardMarginHeight = cardHeight + cardMargin;
constexpr float tableHeight = 0.01f;

enum struct MouseButtonState {
    Up,
    Pressed,
    Down,
    Released,
};

struct Mouse {
    int screenX; // Coordinates on the screen
    int screenY;
    float tableX; // 3D coordinates on the table plane
    float tableZ;
    float tableScaledX; // 3D coordinates scaled for card size
    float tableScaledZ;
    int gridX; // Coordinates on the table card grid
    int gridY;
    int wheel;
    MouseButtonState left;
    MouseButtonState right;
};

struct Input {
    float dt;
    Mouse mouse;
};

struct GameCamera {
    Vector3 target;
    Vector3 offset;
    Camera3D camera;
};

struct PlatformContext {
    int windowWidth;
    int windowHeight;
    GameCamera camera;
    Input input;
};

namespace platform
{
PlatformContext *pctx;
}
