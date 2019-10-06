using std::ceil;
using std::cout;
using std::endl;
using std::floor;
using std::get;
using std::runtime_error;
using std::string;
using std::to_string;
using std::variant;
using std::vector;

using json = nlohmann::json;
using Color = SDL_Color;

using cstring = const char *;
using EntityId = unsigned int;
using ComponentMask = unsigned long long int;

constexpr int MAP_WIDTH = 256;
constexpr int MAP_HEIGHT = 256;
constexpr EntityId ENTITY_POOL = 256;

constexpr Color LIGHTGRAY = {200, 200, 200, 255};
constexpr Color GRAY = {130, 130, 130, 255};
constexpr Color DARKGRAY = {80, 80, 80, 255};
constexpr Color YELLOW = {253, 249, 0, 255};
constexpr Color GOLD = {255, 203, 0, 255};
constexpr Color ORANGE = {255, 161, 0, 255};
constexpr Color PINK = {255, 109, 194, 255};
constexpr Color RED = {230, 41, 55, 255};
constexpr Color MAROON = {190, 33, 55, 255};
constexpr Color GREEN = {0, 228, 48, 255};
constexpr Color LIME = {0, 158, 47, 255};
constexpr Color DARKGREEN = {0, 117, 44, 255};
constexpr Color SKYBLUE = {102, 191, 255, 255};
constexpr Color BLUE = {0, 121, 241, 255};
constexpr Color DARKBLUE = {0, 82, 172, 255};
constexpr Color PURPLE = {200, 122, 255, 255};
constexpr Color VIOLET = {135, 60, 190, 255};
constexpr Color DARKPURPLE = {112, 31, 126, 255};
constexpr Color BEIGE = {211, 176, 131, 255};
constexpr Color BROWN = {127, 106, 79, 255};
constexpr Color DARKBROWN = {76, 63, 47, 255};
constexpr Color WHITE = {255, 255, 255, 255};
constexpr Color BLACK = {0, 0, 0, 255};
constexpr Color BLANK = {0, 0, 0, 0};
constexpr Color MAGENTA = {255, 0, 255, 255};
