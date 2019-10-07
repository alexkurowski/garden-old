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
