#pragma once

#include "Sprite.h"
#include <stdio.h>

#include <GL/gl.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

// GameObject contians infomation about what vertex data to manipulate and how
// This also allows textured quads to be reused
class GameObject {
public:
    GameObject(const char* spritePath, glm::vec3 position,
        int shaderProgramID=0, glm::vec3 rotation=glm::vec3(0));

    void updateModel();
    glm::mat4 getModel();

    void setPosition(glm::vec3 position);
    void addPosition(glm::vec3 position);
    glm::vec3 getPosition() const;

    void setRotation(glm::vec3 rotation);
    glm::vec3 getRotation() const;

    void setScale(glm::vec3 scale);
    glm::vec3 getScale() const;

    int getShaderProgramID();
    void setShaderProgram(int shaderProgramID);

    GLuint getSpriteID() const;
    void setSpriteID(int spriteID);
    const char* getSpritePath() const;
    void setScaleBySprite(const Sprite sprite);
    
    virtual void logic() = 0;

protected:
    glm::mat4 model;

    glm::vec3 position;
    glm::vec3 rotation;
    glm::vec3 scale;

    int spriteID;
    const char* spritePath;

    int shaderProgramID;

    bool needsUpdate;
    const bool isStatic;
};