namespace platform
{

static Command getCommand()
{
    char key = pctx->input.keyboard.keyPressed;
    char lkey = tolower(key);

    if (lkey == 'j') {
        return Command::GoS;
    } else if (lkey == 'k') {
        return Command::GoN;
    } else if (lkey == 'h') {
        return Command::GoW;
    } else if (lkey == 'l') {
        return Command::GoE;
    } else if (lkey == 'y') {
        return Command::GoNW;
    } else if (lkey == 'u') {
        return Command::GoNE;
    } else if (lkey == 'b') {
        return Command::GoSW;
    } else if (lkey == 'n') {
        return Command::GoSE;
    } else {
        return Command::None;
    }
}

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

    input.keyboard.shift =
        IsKeyDown(KEY_LEFT_SHIFT) || IsKeyDown(KEY_RIGHT_SHIFT);
    input.keyboard.ctrl =
        IsKeyDown(KEY_LEFT_CONTROL) || IsKeyDown(KEY_RIGHT_CONTROL);
    input.keyboard.alt = IsKeyDown(KEY_LEFT_ALT) || IsKeyDown(KEY_RIGHT_ALT);
    input.keyboard.keyPressed = (char)GetKeyPressed();

    input.mouse.screenX = GetMouseX();
    input.mouse.screenY = GetMouseY();
    input.mouse.tileX = input.mouse.screenX / (tileWidth * pctx->scale);
    input.mouse.tileY = input.mouse.screenY / (tileHeight * pctx->scale);
    input.mouse.left = getMouseButtonState(0);
    input.mouse.right = getMouseButtonState(1);

    input.cmd = getCommand();

    return input;
}

} // namespace platform
