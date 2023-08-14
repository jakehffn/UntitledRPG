#pragma once

#include <iostream>
#include <unordered_set>
#include <cassert>

#include <entt/entt.hpp>
#include <SDL.h>
#ifndef NDEBUG
    #include "imgui_impl_opengl3.h"
    #include "imgui_impl_sdl2.h"
#endif

#include "system.hpp"
#include "clock.hpp"

#include "consts.hpp"

class Input {
public:
    Input();
    void update();

    bool isActive(SDL_Keycode key);
    bool isAdded(SDL_Keycode key);
    bool isRemoved(SDL_Keycode key);
    bool isQuit();

    int getMouseX();
    int getMouseY();

private:

    int mouse_x;
    int mouse_y;

    SDL_Event e;
    bool quit;

    std::unordered_set<SDL_Keycode> active; 
    std::unordered_set<SDL_Keycode> added; 
    std::unordered_set<SDL_Keycode> removed; 
};