#include "main.h"

#include "content/components.cpp"
#include "content/entities.cpp"
#include "content/tiles.cpp"
#include "content/map.cpp"
#include "content/fov.cpp"
#include "blueprints/test.cpp"
#include "systems/fov.cpp"
#include "systems/global.cpp"
#include "systems/test.cpp"
#include "systems/tiles.cpp"
#include "systems/sprites.cpp"
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
