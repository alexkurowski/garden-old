#include <iostream>
#include <vector>
#include <variant>
#include <stdexcept>
#include <cmath>

#include <SDL2/SDL.h>
#include <SDL2/SDL_gpu.h>

#define STB_PERLIN_IMPLEMENTATION 1
#include "stb_perlin.h"

#include "json.hpp"

#include "helpers/alias.h"
#include "helpers/math.h"
#include "helpers/text.h"

#include "content/components.h"
#include "content/entities.h"
#include "content/tiles.h"
#include "content/map.h"
#include "game/game.h"
#include "platform/platform.h"
#include "platform/draw.h"
