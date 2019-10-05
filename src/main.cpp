#include <stdio.h>
#include <GLFW/glfw3.h>
#include "Class/Hello.h"
#include <glm/vec3.hpp>
#include <glad/glad.h>

static void error_callback(int error, const char* description)
{
    fprintf(stderr, "Error %d: %s\n", error, description);
}


int main(int argc, char const *argv[])
{
    glm::vec3 vec = glm::vec3(1,0,0);
    printf("{%f, %f, %f}\n", vec[0], vec[1], vec[2]);

	Hello *h = new Hello();
	h->print();

	glfwSetErrorCallback(error_callback);
    if (!glfwInit())
        return 1;
    glfwWindowHint(GLFW_SAMPLES, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(1280, 720, "ImGui OpenGL3 example", NULL, NULL);
    glfwMakeContextCurrent(window);

    while (!glfwWindowShouldClose(window)){
    	glfwPollEvents();
    }

	glfwTerminate();

	return 0;
}
