#include "BackgroundObject.h"

BackgroundObject::BackgroundObject(Clock* clock, GLuint shaderProgramID) :
    GameObject("./src/assets/sprites/Untitled.png", glm::vec3(0, 0, -.1)), clock{ clock } {}

void BackgroundObject::logic() {}