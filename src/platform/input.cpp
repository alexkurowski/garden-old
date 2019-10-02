namespace platform
{

static Input &input()
{
    Input &input = pctx->input;
    input.mouseX = GetMouseX();
    input.mouseY = GetMouseY();
    return input;
}

} // namespace platform
