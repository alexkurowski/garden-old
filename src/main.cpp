#include "main.h"

#include "content/components.cpp"
#include "content/entities.cpp"
#include "systems/global.cpp"
#include "systems/test.cpp"
#include "game/game.cpp"
#include "platform/camera.cpp"
#include "platform/render.cpp"
#include "platform/input.cpp"
#include "platform/platform.cpp"

int main()
{
    platform::init();
    game::init();
    platform::mainLoop();
    game::quit();
    platform::quit();
    return 0;
}
