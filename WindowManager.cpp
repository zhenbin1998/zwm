#include "WindowManager.hpp"

WindowManager::WindowManager(Display* _display)
                                :display(_display),
                                screen(DefaultScreenOfDisplay(_display)),
                                rootWindow(DefaultRootWindow(_display)),
                                displayHeight(screen->height),
                                displayWidth(screen->width)
{
  eventManager = new EventManager(_display);
}

std::unique_ptr<WindowManager> WindowManager::Create()
{
    Display * display_ = XOpenDisplay(nullptr);
    if (display_ == nullptr) {
    std::cerr << "Failed to open X display " << XDisplayName(nullptr) << std::endl;
    return nullptr;
  }
  std::cout << "Open X display " << XDisplayName(nullptr) << std::endl;
  return std::unique_ptr<WindowManager>(new WindowManager(display_));
}

WindowManager::~WindowManager()
{
  XCloseDisplay(display);
}

int WindowManager::XError(Display *_display, XErrorEvent * _event)
{
  const int MAX_ERROR_TEXT_LENGTH = 1024;
  char error_text[MAX_ERROR_TEXT_LENGTH];
  XGetErrorText(_display, _event->error_code, error_text, sizeof(error_text));
  std::cerr << "Received X error:\n"
             << "    Request: " << int(_event->request_code)
             //<< " - " << XRequestCodeToString(_event->request_code) << "\n"
             << "    Error code: " << int(_event->error_code)
             << " - " << error_text << "\n"
             << "    Resource ID: " << _event->resourceid;
  return 0;
}

void WindowManager::WindowFrame(Window _window)
{

}

void WindowManager::Run() 
{
  //   b. Set error handler.
  XSetErrorHandler(XError);
  // //  c. Grab X server to prevent windows from changing under us.
  // XGrabServer(display);
  // //   d. Reparent existing top-level windows.
  // //      i. Query existing top-level windows.
  // Window returned_root, returned_parent;
  // Window* top_level_windows;
  // unsigned int num_top_level_windows;
  // XQueryTree(
  //     display,
  //     rootWindow,
  //     &returned_root,
  //     &returned_parent,
  //     &top_level_windows,
  //     &num_top_level_windows);
  // std::cout << "Existing windows num: " << num_top_level_windows << std::endl;
  // //     ii. Frame each top-level window.
  // for (unsigned int i = 0; i < num_top_level_windows; ++i) {
  //   //Frame(top_level_windows[i], true);
  // }
  // //     iii. Free top-level window array.
  // XFree(top_level_windows);
  // //   e. Ungrab X server.
  // XUngrabServer(display);
  eventManager->Run();
 }

