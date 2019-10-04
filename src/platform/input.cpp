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
    input.mouse.wheel = GetMouseWheelMove();
    input.mouse.left = getMouseButtonState(0);
    input.mouse.right = getMouseButtonState(1);

    Ray mouseRay = GetMouseRay(GetMousePosition(), pctx->camera.camera);
    RayHitInfo hitInfo = GetCollisionRayGround(mouseRay, 0);
    input.mouse.tableX = hitInfo.position.x;
    input.mouse.tableZ = hitInfo.position.z;

    input.mouse.tableScaledX = input.mouse.tableX / cardMarginWidth;
    input.mouse.tableScaledZ = input.mouse.tableZ / cardMarginHeight;
    input.mouse.gridX = floor(input.mouse.tableScaledX + 0.5);
    input.mouse.gridY = floor(input.mouse.tableScaledZ + 0.5);

    cameraControls();
    updateCamera();

    return input;
}

} // namespace platform
