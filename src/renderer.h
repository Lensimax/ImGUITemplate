#ifndef RENDERER_H
#define RENDERER_H

#include "shader.h"

#ifndef GLM_H
#define GLM_H
#include <glm/glm.hpp>
#include <glm/ext/matrix_transform.hpp>
#include <glm/ext/matrix_clip_space.hpp>
#include <glm/gtc/matrix_inverse.hpp>
#endif


class Renderer {

public:
    Renderer();
    ~Renderer();

    // display the UI
    void createUI();

    // update your objects, camera, light; etc.
    void update();

    // compute the scene and display it on the screen
    void paintGL(int width, int height);

private:

    void initGL();

    Shader *shader;

    void createCubeVAO();
    void deleteCubeVAO();

    glm::vec3 cubePosition, cubeRotation, cubeScale;

    GLuint _cube;
    GLuint _vaoCube;
};


#endif