enum struct TileType {
    Blank,
    Grass,
    Tree,
};

struct TileData {
    Point sprite;
    Color color;
    bool canSee;
    bool canWalk;
};

constexpr bool CAN_SEE = true;
constexpr bool CAN_WALK = true;
constexpr bool CANT_SEE = false;
constexpr bool CANT_WALK = false;

using TileVariant = int;
using TileDataMap = unordered_map<TileType, vector<TileData>>;
