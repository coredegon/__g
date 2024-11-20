#include "AppWindow.h"

int main()
{
    AppWindow& wnd = AppWindow::getInstance(1280,720,"Singleton Window");
    wnd.setWindowClearColor(0.8f, 0.2f, 0.4f, 1.0f);
    wnd.loop();
    return 0;
}
