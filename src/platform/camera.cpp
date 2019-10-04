namespace platform
{

constexpr float cameraSpeed = 8.0f;
constexpr float cameraEase = 8.0f;
constexpr float cameraAngle = 75.0f;
constexpr float cameraDistanceSpeed = 8.0f;
constexpr float cameraMinDistance = 5.0f;
constexpr float cameraMaxDistance = 50.0f;

void setupCamera()
{
    pctx->camera.target = {0.0f, 0.0f, 0.0f};
    pctx->camera.distance = pctx->camera.distanceTarget = 20.0f;

    Camera3D &camera = pctx->camera.camera;
    camera.up = {0.0f, 1.0f, 0.0f};
    camera.fovy = 60.0f;
    camera.type = CAMERA_PERSPECTIVE;
}

void cameraControls()
{
    Vector3 &target = pctx->camera.target;
    float &distanceTarget = pctx->camera.distanceTarget;
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

    if (pctx->input.mouse.wheel != 0) {
        distanceTarget -= pctx->input.mouse.wheel * cameraDistanceSpeed * dt;
    }
    if (distanceTarget < cameraMinDistance) {
        distanceTarget = cameraMinDistance;
    }
    if (distanceTarget > cameraMaxDistance) {
        distanceTarget = cameraMaxDistance;
    }
}

void updateCamera()
{
    Camera3D &camera = pctx->camera.camera;
    float ease = cameraEase * pctx->input.dt;
    float rad = cameraAngle / 180 * PI;

    pctx->camera.distance +=
        (pctx->camera.distanceTarget - pctx->camera.distance) * ease;
    Vector3 offset = {0.f,
                      sin(rad) * pctx->camera.distance,
                      cos(rad) * pctx->camera.distance};

    camera.target.x += (pctx->camera.target.x - camera.target.x) * ease;
    camera.target.y += (pctx->camera.target.y - camera.target.y) * ease;
    camera.target.z += (pctx->camera.target.z - camera.target.z) * ease;
    camera.position.x = camera.target.x + offset.x;
    camera.position.y = camera.target.y + offset.y;
    camera.position.z = camera.target.z + offset.z;
}

} // namespace platform
