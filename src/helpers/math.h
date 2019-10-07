struct Point {
    int x, y;
};

struct Vector2 {
    float x, y;
};

struct Rect {
    int x, y, w, h;
};

struct Rectf {
    float x, y, w, h;
};

inline static int random(int min, int max)
{
    return min + (rand() % (max - min + 1));
}

inline static float noiseAt(float x, float y, int seed = 0)
{
    return stb_perlin_noise3_seed(x, y, 0, 0, 0, 0, seed) + 0.5f;
}

inline static bool inside(Rect bounds, int x, int y)
{
    return x >= bounds.x && x < bounds.x + bounds.w && y >= bounds.y &&
        y < bounds.y + bounds.h;
}

inline static bool inside(Rectf bounds, float x, float y)
{
    return x >= bounds.x && x < bounds.x + bounds.w && y >= bounds.y &&
        y < bounds.y + bounds.h;
}

inline static bool outside(Rect bounds, int x, int y)
{
    return x < bounds.x || x >= bounds.x + bounds.w || y < bounds.y ||
        y >= bounds.y + bounds.h;
}

inline static bool outside(Rectf bounds, float x, float y)
{
    return x < bounds.x || x >= bounds.x + bounds.w || y < bounds.y ||
        y >= bounds.y + bounds.h;
}
