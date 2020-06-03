#ifndef EVENTMANAGER_HPP
#define EVENTMANAGER_HPP

#include "include.hpp"

struct OnEvents
{
    int eventType;
    std::string eventName;
    void (*event)(XEvent *e);
};

typedef struct XArg{
    const char** com;
    const int i;
    const Window w;
} ;
typedef struct XKey
{
    uint mod;
    KeySym keysym;
    void (*function)(const XArg arg);
    const XArg arg;
};

class EventManager
{
private:
    //typedef void(*eventsFunPtr[LASTEvent])(XEvent * _event) = {nullptr};
    static Display *display;
    XEvent event;
    OnEvents onEvent[LASTEvent + 1] = {
        {0, "", nullptr},
        {1, "", nullptr},
        //Keyboard events
        {2, "KeyPress", keyPress}, 
        {3, "KeyRelease", nullptr},
        //Pointer events
        {4, "ButtonPress", buttonPress},
        {5, "ButtonRelease", buttonRelease},
        {6, "MotionNotify", motionNotify},
        //Window crossing events
        {7, "EnterNotify", enterNotify},
        {8, "LeaveNotify", nullptr},
        //Input focus events
        {9, "FocusIn", nullptr},
        {10, "FocusOut", nullptr},
        //Keymap state notification event
        {11, "KeymapNotify", nullptr},
        //Exposure events
        {12, "Expose", nullptr},
        {13, "GraphicsExpose", nullptr},
        {14, "NoExpose", nullptr},
//Structure control events and Window state notification events
        {15, "VisibilityNotify", nullptr},
        {16, "CreateNotify", nullptr},
        {17, "DestroyNotify", destroyNotify},
        {18, "UnmapNotify", nullptr},
        {19, "MapNotify", nullptr},
        {20, "MapRequest", mapRequest},
        {21, "ReparentNotify", nullptr},
        {22, "ConfigureNotify", nullptr},
        {23, "ConfigureRequest", configureRequest},
        {24, "GravityNotify", nullptr},
        {25, "ResizeRequest", nullptr},
        {26, "CirculateNotify", nullptr},
        {27, "CirculateRequest", nullptr},
        {28, "PropertyNotify", nullptr},
        {29, "SelectionClear", nullptr},
        {30, "SelectionRequest", nullptr},
        {31, "SelectionNotify", nullptr},
        //Colormap state notification event
        {32, "ColormapNotify", nullptr},
        //Client communication events
        {33, "ClientMessage", nullptr},
        
        {34, "MappingNotify", nullptr},
        {35, "GenericEvent", nullptr},
        {36, "LASTEvent", nullptr}};

public:
    EventManager(Display *_display);
    ~EventManager();
    void Run();
    
    static void buttonPress(XEvent *_event);
    static void buttonRelease(XEvent *_event);
    static void motionNotify(XEvent *_event);

    static void configureRequest(XEvent *_event);
    static void keyPress(XEvent *_event);
    static void mapRequest(XEvent *_event);
    static void destroyNotify(XEvent *_event);
    static void enterNotify(XEvent *_event);
    
};

#endif //EVENTMANAGER_HPP