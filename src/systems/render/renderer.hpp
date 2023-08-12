#include <vector>

#include "imgui_impl_opengl3.h"
#include "imgui_impl_sdl2.h"

#include "consts.hpp"
#include "shader_program.hpp"
#include "screen_shader.hpp"
#include "instanced_shader.hpp"

class Renderer {
public:
    Renderer();
    ~Renderer();

    void addBufferData(const glm::vec4& texture_data, const glm::mat4& model_data);
    void render(const glm::mat4& view, const glm::mat4& projection, const glm::vec2& atlas_dimensions, GLuint atlas_texture, double time);
    GLuint getScreenTexture();
private:
    void initVAO();
    void initVBOs();
    void initScreenFBO();
    void initFinalFBO();

    void bufferData();

    GLuint vao;

    GLuint screen_fbo;
    GLuint screen_texture;

    GLuint final_fbo;
    GLuint final_texture;

    GLuint texture_coordinates_vbo;
    std::vector<glm::vec4> texture_coordinates_buffer_data; 

    GLuint models_vbo;
    std::vector<glm::mat4> models_buffer_data;

    size_t maxBufferSize{0}; 

    InstancedShader* instanced_shader;
    ShaderProgram<double>* screen_shader;
};