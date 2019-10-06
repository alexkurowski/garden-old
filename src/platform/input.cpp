namespace platform
{

static MouseButtonState getMouseButtonState(int button)
{
    if (IsMouseButtonPressed(button)) {
        return MouseButtonState::Pressed;
    } else if (IsMouseButtonReleased(button)) {
        return MouseButtonState::Released;
    } else if (IsMouseButtonDown(button)) {
        return MouseButtonState::Down;
    } else {
        return MouseButtonState::Up;
    }
}

static Input &input()
{
    Input &input = pctx->input;

    input.dt = GetFrameTime();

    input.mouse.screenX = GetMouseX();
    input.mouse.screenY = GetMouseY();
    input.mouse.tileX = input.mouse.screenX / (tileWidth * scale);
    input.mouse.tileY = input.mouse.screenY / (tileHeight * scale);
    input.mouse.left = getMouseButtonState(0);
    input.mouse.right = getMouseButtonState(1);

    return input;
}

} // namespace platform
