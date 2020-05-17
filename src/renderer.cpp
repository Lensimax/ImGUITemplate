#include "renderer.h"

#include <imgui.h>

Renderer::Renderer(){

    cubePosition = glm::vec3(0,0,0);
    cubeRotation = glm::vec3(0,0,0);
    cubeScale = glm::vec3(1,1,1);

    cubeColor = glm::vec4(1,0,0,1);

    // creation du shader
    shader = new Shader();
    shader->load("../data/shaders/display.vert", "../data/shaders/display.frag");


    createCubeVAO();
}


Renderer::~Renderer(){
    deleteCubeVAO();
}


void Renderer::initGL(){

    //// OPENGL OPTIONS

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_TEXTURE_2D);
    glDepthMask(GL_TRUE);
    glDepthFunc(GL_LESS);
    glEnable(GL_POLYGON_OFFSET_LINE);
    glPolygonOffset(-1,-1);

    // Cull triangles which normal is not towards the camera
    glDisable(GL_CULL_FACE);
    // glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
}

// display the UI
void Renderer::createUI(){

    const float lowestValue = -1000.0f;
    const float highestValue = 1000.0f;

    // format d'affichage
    const char *format = "%.3f";

    ImGui::Begin("Cube");

    ImGui::Text("Transform");

    ImGui::Text("Position: "); ImGui::SameLine();
    ImGui::DragFloat3("##position", &cubePosition[0], 0.01f, lowestValue, highestValue, format);
    ImGui::Text("Rotation: "); ImGui::SameLine();
    ImGui::DragFloat3("##rotation", &cubeRotation[0], 0.01f, lowestValue, highestValue, format);
    ImGui::Text("Scale: "); ImGui::SameLine();
    ImGui::DragFloat3("##scale", &cubeScale[0], 0.005f, 0.0f, highestValue, format);

    ImGui::Separator();
    ImGui::Text("Color");
    ImGui::Text("Color: "); ImGui::SameLine();
    ImGui::ColorEdit4("##color", (float *)&cubeColor);

    ImGui::End();

}

// update your objects, camera, light; etc.
void Renderer::update(){

}

// compute the scene and display it on the screen
void Renderer::paintGL(int width, int height){

    // COMPUTE MATRICES
    // model matrix
    glm::mat4 modelMat = glm::mat4(1);
    modelMat = translate(modelMat, cubePosition);
    modelMat = glm::scale(modelMat, cubeScale);
    modelMat = glm::rotate(modelMat, cubeRotation[0], glm::vec3(1.0,0.0,0.0));
    modelMat = glm::rotate(modelMat, cubeRotation[1], glm::vec3(0.0,1.0,0.0));
    modelMat = glm::rotate(modelMat, cubeRotation[2], glm::vec3(0.0,0.0,1.0));

    // view matrix
    const glm::vec3 position = glm::vec3(0,0,5);
    const glm::vec3 directionOfView = glm::vec3(0,0,0);
    const glm::vec3 vectorUp = glm::vec3(0,1,0);
    glm::mat4 viewMat = glm::lookAt(position, directionOfView, vectorUp);

    // projection matrix
    const float fov = 45.0f;
    const float nearCam = 0.1f;
    const float farCam = 100.0f;
    glm::mat4 projMat = glm::perspective(fov, (float)width/(float)height, nearCam, farCam);

    initGL();

    glViewport(0,0,width,height);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glUseProgram(shader->id());

    // send uniform
    // send matrix
    glUniformMatrix4fv(glGetUniformLocation(shader->id(),"modelMat"),1,GL_FALSE,&(modelMat[0][0]));
    glUniformMatrix4fv(glGetUniformLocation(shader->id(),"viewMat"),1,GL_FALSE,&(viewMat[0][0]));
    glUniformMatrix4fv(glGetUniformLocation(shader->id(),"projMat"),1,GL_FALSE,&(projMat[0][0]));

    // send color
    glUniform4fv(glGetUniformLocation(shader->id(),"color"),1,&(cubeColor[0]));

    drawCube();

    glUseProgram(0);

}

// creation of the VAO for the cube
void Renderer::createCubeVAO(){
    const GLfloat cubeData[] = {
        -1.0f,-1.0f,-1.0f, // triangle 1 : begin
    -1.0f,-1.0f, 1.0f,
    -1.0f, 1.0f, 1.0f, // triangle 1 : end
    1.0f, 1.0f,-1.0f, // triangle 2 : begin
    -1.0f,-1.0f,-1.0f,
    -1.0f, 1.0f,-1.0f, // triangle 2 : end
    1.0f,-1.0f, 1.0f,
    -1.0f,-1.0f,-1.0f,
    1.0f,-1.0f,-1.0f,
    1.0f, 1.0f,-1.0f,
    1.0f,-1.0f,-1.0f,
    -1.0f,-1.0f,-1.0f,
    -1.0f,-1.0f,-1.0f,
    -1.0f, 1.0f, 1.0f,
    -1.0f, 1.0f,-1.0f,
    1.0f,-1.0f, 1.0f,
    -1.0f,-1.0f, 1.0f,
    -1.0f,-1.0f,-1.0f,
    -1.0f, 1.0f, 1.0f,
    -1.0f,-1.0f, 1.0f,
    1.0f,-1.0f, 1.0f,
    1.0f, 1.0f, 1.0f,
    1.0f,-1.0f,-1.0f,
    1.0f, 1.0f,-1.0f,
    1.0f,-1.0f,-1.0f,
    1.0f, 1.0f, 1.0f,
    1.0f,-1.0f, 1.0f,
    1.0f, 1.0f, 1.0f,
    1.0f, 1.0f,-1.0f,
    -1.0f, 1.0f,-1.0f,
    1.0f, 1.0f, 1.0f,
    -1.0f, 1.0f,-1.0f,
    -1.0f, 1.0f, 1.0f,
    1.0f, 1.0f, 1.0f,
    -1.0f, 1.0f, 1.0f,
    1.0f,-1.0f, 1.0f
    };

    glGenBuffers(1,&_cube);
    glGenVertexArrays(1,&_vaoCube);

    glBindVertexArray(_vaoCube);
    glBindBuffer(GL_ARRAY_BUFFER,_cube); // vertices
    glBufferData(GL_ARRAY_BUFFER, sizeof(cubeData),cubeData,GL_STATIC_DRAW);
    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,0,(void *)0);
    glEnableVertexAttribArray(0);
}

// delete the VAO
void Renderer::deleteCubeVAO(){
    glDeleteBuffers(1,&_cube);
    glDeleteVertexArrays(1,&_vaoCube);
}



// method to draw the cube
void Renderer::drawCube(){

    const unsigned int numberOfTriangles = 12;

    glBindVertexArray(_vaoCube);
    glDrawArrays(GL_TRIANGLES,0,numberOfTriangles*3);
    glBindVertexArray(0);    
}