
// App.cpp
#include "App.h"
#include "Model.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>


void App::run() {
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(800, 600, "Circle", NULL, NULL);
    if (!window) {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return;
    }
    glfwMakeContextCurrent(window);

    if (glewInit() != GLEW_OK) {
        std::cerr << "Failed to initialize GLEW" << std::endl;
        return;
    }

    
    int segments = 100;
    Model modelo(segments);
    modelo.createCircle(0.5);
    modelo.initializeModel();
    modelo.bindShader("shaders/vertex.glsl", "shaders/fragment.glsl");


    while (!glfwWindowShouldClose(window)) {
        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
            glfwSetWindowShouldClose(window, true);

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

       modelo.draw();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

   
    glfwTerminate();
}
