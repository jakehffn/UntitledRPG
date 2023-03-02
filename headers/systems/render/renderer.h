#include <vector>

#include "consts.h"
#include "shader_program.h"
#include "screen_shader.h"
#include "instanced_shader.h"

class Renderer {
public:
    Renderer();
    ~Renderer();

    void addBufferData(const glm::vec4& textureData, const glm::mat4& modelData);
    void render(const glm::mat4& view, const glm::mat4& projection, const glm::vec2& atlasDim, GLuint atlasTexture, double time);

private:
    void initVAO();
    void initVBOs();
    void initScreenFBO();

    void bufferData();

    GLuint VAO;

    GLuint screenFBO;
    GLuint screenTexture;

    GLuint textureCoordinatesVBO;
    std::vector<glm::vec4> textureCoordinatesBufferData; 

    GLuint modelsVBO;
    std::vector<glm::mat4> modelsBufferData; 

    InstancedShader* instancedShader;
    ShaderProgram<double>* screenShader;
};