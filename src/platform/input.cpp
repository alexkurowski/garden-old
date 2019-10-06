namespace platform
{

static Command getCommand()
{
    char key = pctx->input.keyboard.keyPressed;
    char lckey = tolower(key);

    if (lckey == 'j') {
        return Command::GoS;
    } else if (lckey == 'k') {
        return Command::GoN;
    } else if (lckey == 'h') {
        return Command::GoW;
    } else if (lckey == 'l') {
        return Command::GoE;
    } else if (lckey == 'y') {
        return Command::GoNW;
    } else if (lckey == 'u') {
        return Command::GoNE;
    } else if (lckey == 'b') {
        return Command::GoSW;
    } else if (lckey == 'n') {
        return Command::GoSE;
    } else {
        return Command::None;
    }
}

// static MouseButtonState getMouseButtonState(int button)
// {
//     if (IsMouseButtonPressed(button)) {
//         return MouseButtonState::Pressed;
//     } else if (IsMouseButtonReleased(button)) {
//         return MouseButtonState::Released;
//     } else if (IsMouseButtonDown(button)) {
//         return MouseButtonState::Down;
//     } else {
//         return MouseButtonState::Up;
//     }
// }

static Input &input(Context *ctx)
{
    SDL_Event *event = &pctx->event;
    Input &input = pctx->input;

    while (SDL_PollEvent(event) != 0) {
        switch (event->type) {
        case SDL_QUIT: {
            pctx->running = false;
        } break;

        case SDL_WINDOWEVENT: {
            switch (event->window.event) {
            case SDL_WINDOWEVENT_RESIZED: {
                handleResize(event->window.data1, event->window.data2);
            } break;
            }
        } break;
        }

        // input.dt = GetFrameTime();

        // input.keyboard.shift =
        //     IsKeyDown(KEY_LEFT_SHIFT) || IsKeyDown(KEY_RIGHT_SHIFT);
        // input.keyboard.ctrl =
        //     IsKeyDown(KEY_LEFT_CONTROL) || IsKeyDown(KEY_RIGHT_CONTROL);
        // input.keyboard.alt =
        //     IsKeyDown(KEY_LEFT_ALT) || IsKeyDown(KEY_RIGHT_ALT);
        // input.keyboard.keyPressed = (char)GetKeyPressed();

        // input.mouse.screenX = GetMouseX();
        // input.mouse.screenY = GetMouseY();
        // Vector2 offset = getCameraOffset(ctx);
        // input.mouse.tileX =
        //     floor((input.mouse.screenX + offset.x) / (tileWidth *
        //     pctx->scale));
        // input.mouse.tileY = floor(
        //     (input.mouse.screenY + offset.y) / (tileHeight * pctx->scale));
        // input.mouse.left = getMouseButtonState(0);
        // input.mouse.right = getMouseButtonState(1);
    }

    // pctx->last = NOW;
    // NOW = SDL_GetPerformanceCounter();
    // input.dt = ((NOW - LAST)*1000 / (double)SDL_GetPerformanceFrequency() );

    input.cmd = getCommand();
    return input;
}

} // namespace platform
