struct Input {
    int mouseX;
    int mouseY;
};

struct PlatformContext {
    int windowWidth;
    int windowHeight;
    Input input;
};

namespace platform
{
PlatformContext *pctx;
}

