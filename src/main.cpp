#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

#define SZ_X 1000
#define SZ_Y 500

void framebufferSizeCallback(GLFWwindow* pWindow, int width, int height);
void processInput(GLFWwindow* pWindow);

int main()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    GLFWwindow* pWindow = glfwCreateWindow(SZ_X,SZ_Y,"Fst window",nullptr, nullptr);
    if(!pWindow)
    {
        std::cout << "@: Window creation failure." << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(pWindow);

    //GLAD
    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "@: GLAD initialization failure." << std::endl;
        return -1;
    }
    glViewport(0,0,SZ_X,SZ_Y);

    glfwSetFramebufferSizeCallback(pWindow, framebufferSizeCallback);

    while(!glfwWindowShouldClose(pWindow))
    {
        processInput(pWindow);

        glfwSwapBuffers(pWindow);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}

void framebufferSizeCallback(GLFWwindow* pWindow, int width, int height)
{
    glViewport(0, 0, width, height);
}

void processInput(GLFWwindow* pWindow)
{
    if(glfwGetKey(pWindow, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(pWindow, true);
}
