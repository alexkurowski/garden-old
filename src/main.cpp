#include "main.h"

#include "game/game.cpp"
#include "platform/input.cpp"
#include "platform/presentation.cpp"
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
