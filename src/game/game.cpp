namespace game
{

static void init()
{
    ctx = new Context;
}

static Context *update(Input &input)
{
    // cout << input.mouseX << endl;
    return ctx;
}

static void quit()
{
    delete ctx;
}

} // namespace game
