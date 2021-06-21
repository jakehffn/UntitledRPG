#pragma once

// GLEW must come before OpenGL
#include <GL\glew.h>
#include <SDL.h>
#include <SDL_opengl.h>

#include "consts.h"

class Sprite {
public:
    Sprite(const char* spritePath);

    GLuint getVAO() const;
    GLuint getTexture() const;

    int getWidth() const;
    int getHeight() const;

private:
    int width;
    int height;
    int nColorChannels;

    GLuint VAO;
    GLuint texture;
};