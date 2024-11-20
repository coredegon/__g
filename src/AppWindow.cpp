#include "AppWindow.h"

AppWindow* AppWindow::pInstance = nullptr;

AppWindow& AppWindow::getInstance(int width, int height, const char* title) {
    if (!pInstance) {
        pInstance = new AppWindow(width, height, title);
    }
    return *pInstance;
}

AppWindow::AppWindow(int width, int height, const char* title) 
    : width(width),
    height(height),
    title(title),
    pWnd(nullptr)
{
    loadGLFW();
    loadContext();
    loadGLAD();
}

AppWindow::~AppWindow()
{
    if (pWnd) {
        glfwDestroyWindow(pWnd);
    }
    glfwTerminate();
}

void AppWindow::setWindowClearColor(GLfloat r, GLfloat g, GLfloat b, GLfloat a)
{
    glClearColor(r,g,b,a);
}

void AppWindow::loop()
{
    while(!glfwWindowShouldClose(pWnd))
    {
        // input
        keyCallback(pWnd);
        // render
        glClear(GL_COLOR_BUFFER_BIT);

        // other things
        glfwPollEvents();
        glfwSwapBuffers(pWnd);
    }
}

inline void AppWindow::loadContext()
{
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    pWnd = glfwCreateWindow(width,height,title,nullptr, nullptr);
    if(!pWnd)
    {
        std::cout << "@: Window creation failure." << std::endl;
        glfwTerminate();
        return;
    }
    glfwMakeContextCurrent(pWnd);

    glfwSetFramebufferSizeCallback(pWnd, windowSizeCallback);
}

inline void AppWindow::loadGLFW()
{
    if (!glfwInit()) {
        std::cout << "@: GLFW initialization failure." << std::endl;
        return;
    }
}

inline void AppWindow::loadGLAD()
{
    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "@: GLAD initialization failure." << std::endl;
        return;
    }
    glViewport(0,0,width,height);
}

void AppWindow::windowSizeCallback(GLFWwindow* pWnd, int width, int height)
{
    glViewport(0, 0, width, height);
}

void AppWindow::keyCallback(GLFWwindow* pWnd)
{
    if(glfwGetKey(pWnd, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(pWnd, true);
}