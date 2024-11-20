#ifndef APP_WINDOW_H
#define APP_WINDOW_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

class AppWindow {
public:
    static AppWindow& getInstance(int width = 800, int height = 600, const char* title = "App Window");

    void loop();
    void setWindowClearColor(GLfloat r, GLfloat g, GLfloat b, GLfloat a);

private:
    // Приватные конструктор и деструктор
    AppWindow(int width, int height, const char* title);
    ~AppWindow();

    void loadContext();
    void loadGLFW();
    void loadGLAD();

    static void windowSizeCallback(GLFWwindow* pWnd, int width, int height);
    static void keyCallback(GLFWwindow* pWnd);

    static AppWindow* pInstance;
    GLFWwindow* pWnd;
    int width;
    int height;
    const char* title;
};

#endif // APP_WINDOW_H