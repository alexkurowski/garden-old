namespace game
{

Context *ctx;

void init()
{
    ctx = new Context;
}

Context *update(Input &input)
{
    // cout << input.mouseX << endl;
    return ctx;
}

void quit()
{
    delete ctx;
}

} // namespace game
