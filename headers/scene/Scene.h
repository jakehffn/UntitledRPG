#pragma once

#include <vector>

#include "Sprite.h"
#include "Map.h"
#include "GameObject.h"
#include "Camera.h"
#include "Clock.h"
#include "ShaderProgram.h"
#include "BasicShader.h"
#include "UserCameraController.h"

class Scene {
public:
    Scene(SDL_Window* window, Clock* clock, Input* input, CameraController* cameraController);

    // Returns ID for shader program (currently just vector pos)
    int addShaderProgram(ShaderProgram* shaderProgram);
    
    void loadMapObjects(Map map);
    GameObject* getGameObject(int gameObjectID);

    // Returns the position of added camera controller
    int addCameraController(CameraController* cameraController);
    void setCameraController(int pos);
    void nextCameraController();

    void loop();

private:

    // Returns ID for obj (currenlty just vector pos)
    int addSprite(const char* spritePath);
    // Returns ID for gameObject (currently just vector pos)
    int addObjectInstance(GameObject* gameObject);

    void renderInstance(GameObject* gameObject);

    void render();
    void logic();

    SDL_Window* window;
    Clock* clock;
    Input* input;

    Camera camera;

    std::vector<CameraController*> cameraControllers;
    int cameraControllerPosition;

    std::vector<ShaderProgram*> shaderPrograms;
    std::vector<Sprite> sprites;
    std::vector<GameObject*> gameObjects;
};