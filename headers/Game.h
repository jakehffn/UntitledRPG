#pragma once

#include <vector>
#include <iostream>
#include <memory>
#include <unordered_map>

// GLEW must come before OpenGL
#include <GL\glew.h>
#include <SDL.h>
#include <SDL_opengl.h>

#include <entt\entt.hpp>

#include "Clock.h"
#include "Camera.h"
#include "InputManager.h"
#include "TextureManager.h"

#include "InputSystem.h"
#include "RenderSystem.h"
#include "CollisionSystem.h"
#include "MovementSystem.h"
#include "AnimationSystem.h"
#include "CameraSystem.h"
#include "GUISystem.h"
#include "MapLoaderSystem.h"

#include "entities.h"

class Game {
public:
    Game(SDL_Window* window);

    void mainLoop();

private:
    SDL_Window* window;

    Clock clock = Clock();
    Camera worldCamera = Camera();
    Camera guiCamera = Camera();
    InputManager inputManager = InputManager();
    TextureManager textureManager = TextureManager();

    std::vector<System*> systems;

    entt::registry registry;
};