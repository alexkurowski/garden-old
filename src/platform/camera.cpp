namespace platform
{

constexpr float cameraSpeed = 8.0f;
constexpr float cameraEase = 8.0f;

void setupCamera()
{
    pctx->camera.target = {0.0f, 0.0f, 0.0f};
    pctx->camera.offset = {0.0f, 20.0f, 5.0f};

    Camera3D &camera = pctx->camera.camera;
    camera.up = {0.0f, 1.0f, 0.0f};
    camera.fovy = 60.0f;
    camera.type = CAMERA_PERSPECTIVE;
}

void cameraControls()
{
    Vector3 &target = pctx->camera.target;
    float dt = pctx->input.dt;

    if (IsKeyDown(KEY_W) || IsKeyDown(KEY_UP)) {
        target.z -= cameraSpeed * dt;
    }
    if (IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN)) {
        target.z += cameraSpeed * dt;
    }
    if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT)) {
        target.x += cameraSpeed * dt;
    }
    if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT)) {
        target.x -= cameraSpeed * dt;
    }
}

void updateCamera()
{
    Camera3D &camera = pctx->camera.camera;
    float ease = cameraEase * pctx->input.dt;

    camera.target.x += (pctx->camera.target.x - camera.target.x) * ease;
    camera.target.y += (pctx->camera.target.y - camera.target.y) * ease;
    camera.target.z += (pctx->camera.target.z - camera.target.z) * ease;
    camera.position.x = camera.target.x + pctx->camera.offset.x;
    camera.position.y = camera.target.y + pctx->camera.offset.y;
    camera.position.z = camera.target.z + pctx->camera.offset.z;
}

} // namespace platform
