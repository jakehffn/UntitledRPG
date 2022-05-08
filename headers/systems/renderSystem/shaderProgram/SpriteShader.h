#pragma once

#include "ShaderProgram.h"
#include <string>

class SpriteShader : public ShaderProgram {
public:
    SpriteShader();

    GLuint getOpenGLShaderProgramID();
    void renderSetup(glm::mat4 model, glm::mat4 view, glm::mat4 projection, glm::vec2 texData);

private:
    GLuint openGLShaderProgramID;

    GLint MVPuniformID;
    GLint MuniformID;
    GLint VuniformID;

    GLuint spriteColorUniformID;
    GLuint texDataUniformID;
};