#ifndef WINDOW_MANAGER_HPP
#define WINDOW_MANAGER_HPP

#include "include.hpp"
#include "EventManager.hpp"
class WindowManager
{
private:
    Display *display;
    const Window rootWindow;
    WindowManager(Display *_display);
    EventManager *eventManager;
    Screen *screen;
    const uint displayHeight;
    const uint displayWidth;

public:
    static std::unique_ptr<WindowManager> Create();
    ~WindowManager();
    void Run();
    //x error handle
    static int XError(Display *_display, XErrorEvent * _event);
    void WindowFrame(Window _window);

};

#endif //WINDOW_MANAGER_HPP
