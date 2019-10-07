#include "main.h"

#include "content/components.cpp"
#include "content/entities.cpp"
#include "content/map.cpp"
#include "blueprints/test.cpp"
#include "systems/global.cpp"
#include "systems/test.cpp"
#include "systems/sprite.cpp"
#include "game/game.cpp"
#include "platform/camera.cpp"
#include "platform/draw.cpp"
#include "platform/input.cpp"
#include "platform/platform.cpp"

int main()
{
    platform::init();
    platform::mainLoop();
    platform::quit();
    return 0;
}
