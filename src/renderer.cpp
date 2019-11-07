#include "renderer.h"


Renderer::Renderer(){

    cubePosition = glm::vec3(0,0,0);
    cubeRotation = glm::vec3(0,0,0);
    cubeScale = glm::vec3(1,1,1);

    initGL();
}


Renderer::~Renderer(){
    
}


void Renderer::initGL(){

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_TEXTURE_2D);
    glDepthMask(GL_TRUE);
    glDepthFunc(GL_LESS);
    glEnable(GL_POLYGON_OFFSET_LINE);
    glPolygonOffset(-1,-1);

    // Cull triangles which normal is not towards the camera
    glDisable(GL_CULL_FACE);
    glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
}

// display the UI
void Renderer::createUI(){

}

// update your objects, camera, light; etc.
void Renderer::update(){

}

// compute the scene and display it on the screen
void Renderer::paintGL(int width, int height){



}


void Renderer::createCubeVAO(){
    const GLfloat cubeData[] = {-1.0f,-1.0f,0.0f, 1.0f,-1.0f,0.0f, -1.0f,1.0f,0.0f, -1.0f,1.0f,0.0f, 1.0f,-1.0f,0.0f, 1.0f,1.0f,0.0f };

    glGenBuffers(1,&_cube);
    glGenVertexArrays(1,&_vaoCube);

    glBindVertexArray(_vaoCube);
    glBindBuffer(GL_ARRAY_BUFFER,_cube); // vertices
    glBufferData(GL_ARRAY_BUFFER, sizeof(cubeData),cubeData,GL_STATIC_DRAW);
    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,0,(void *)0);
    glEnableVertexAttribArray(0);
}