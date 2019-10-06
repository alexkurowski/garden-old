namespace platform
{

static Command getCommand(Context *ctx)
{
    char key = pctx->input.keyboard.keyPressed;

    switch (key) {
    case 'j':
        return Command::GoS;
    case 'k':
        return Command::GoN;
    case 'h':
        return Command::GoW;
    case 'l':
        return Command::GoE;
    case 'y':
        return Command::GoNW;
    case 'u':
        return Command::GoNE;
    case 'b':
        return Command::GoSW;
    case 'n':
        return Command::GoSE;
    default:
        return Command::None;
    }
}

static void handleKeyboard(SDL_Event &event)
{
    pctx->input.keyboard.keyPressed = event.key.keysym.sym;
}

static void handleMouseButton(SDL_Event &event)
{
    switch (event.button.button) {
    case SDL_BUTTON_LEFT: {
        pctx->input.mouse.btnPressed = 0;
    } break;

    case SDL_BUTTON_RIGHT: {
        pctx->input.mouse.btnPressed = 1;
    } break;
    }
}

static void handleMousePosition(Context *ctx)
{
    int x, y;
    SDL_GetMouseState(&x, &y);

    Vector2 offset = getCameraOffset(ctx);
    float scaleDiff = pctx->scale / initialScale;

    pctx->input.mouse.screen.x = x;
    pctx->input.mouse.screen.y = y;
    pctx->input.mouse.tile.x =
        floor((x - offset.x / scaleDiff) / (tileWidth * initialScale));
    pctx->input.mouse.tile.y =
        floor((y - offset.y / scaleDiff) / (tileHeight * initialScale));
    pctx->input.mouse.text.x = floor(x / (charWidth * initialScale));
    pctx->input.mouse.text.y = floor(y / (charHeight * initialScale));
}

static Input &input(Context *ctx)
{
    SDL_Event &event = pctx->event;
    Input &input = pctx->input;

    input.keyboard.keyPressed = -1;
    input.mouse.btnPressed = -1;

    while (SDL_PollEvent(&event)) {
        switch (event.type) {
        case SDL_QUIT: {
            pctx->running = false;
        } break;

        case SDL_WINDOWEVENT: {
            switch (event.window.event) {
            case SDL_WINDOWEVENT_RESIZED: {
                handleResize(event.window.data1, event.window.data2);
            } break;
            }
        } break;

        case SDL_KEYDOWN: {
            handleKeyboard(event);
        } break;

        case SDL_MOUSEBUTTONDOWN: {
            handleMouseButton(event);
        } break;
        }
    }

    handleMousePosition(ctx);

    input.cmd = getCommand(ctx);

    pctx->lastFrame = pctx->currentFrame;
    pctx->currentFrame = SDL_GetPerformanceCounter();
    input.dt =
        ((pctx->currentFrame - pctx->lastFrame) /
         (double)SDL_GetPerformanceFrequency());

    return input;
}

} // namespace platform
