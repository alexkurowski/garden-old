enum struct TileType {
    Blank,
    Grass,
    Tree,
};

using TileVariant = int;

struct TileData {
    Point sprite;
    Color color;
};

using TileDataMap = unordered_map<TileType, vector<TileData>>;

namespace tiles
{

static TileDataMap data;

static void initData()
{
    // clang-format off
    data = {
        {
            TileType::Blank,
            {
                {{0, 0}, BLANK},
            }
        },
        {
            TileType::Grass,
            {
                {{1, 0}, GREEN},
                {{1, 0}, DARKGREEN},
                {{5, 0}, GREEN},
                {{5, 0}, DARKGREEN},
                {{6, 0}, GREEN},
                {{6, 0}, DARKGREEN},
            }
        },
        {
            TileType::Tree,
            {
                {{0, 1}, GREEN},
                {{0, 1}, DARKGREEN},
                {{1, 1}, GREEN},
                {{1, 1}, DARKGREEN},
                {{2, 1}, GREEN},
                {{2, 1}, DARKGREEN},
                {{3, 1}, GREEN},
                {{3, 1}, DARKGREEN},
                {{4, 1}, GREEN},
                {{4, 1}, DARKGREEN},
            }
        },
    };
    // clang-format on
}

} // namespace tiles
