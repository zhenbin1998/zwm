#include "EventManager.hpp"

EventManager::EventManager(Display * _display)
                            :display(_display)
{
}

EventManager::~EventManager()
{
}

void EventManager::Run()
{
    std::cout << onEvent[KeyPress].eventType << std::endl;
        while (1 ||  !XNextEvent(display, &event)) // 1 && will forever be here.
        if (onEvent[event.type].event)
        {
            std::cout << onEvent[event.type].eventName << std::endl;
            onEvent[event.type].event(&event);
        }
}

void EventManager::buttonPress(XEvent* _event)
{
    std::cout << "buttonPress" << std::endl;
}

void EventManager::buttonRelease(XEvent* _event)
{

}

void EventManager::configureRequest(XEvent* _event)
{

}

void EventManager::motionNotify(XEvent* _event)
{

}

void EventManager::keyPress(XEvent* _event)
{
    std::cout << "buttonPress" << std::endl;
    KeySym keysym = XkbKeycodeToKeysym(display, _event->xkey.keycode, 0, 0);
    std::cout << keysym << std::endl;
}

void EventManager::mapRequest(XEvent* _event)
{

}

void EventManager::destroyNotify(XEvent*  _event)
{

}

void EventManager::enterNotify(XEvent* _event)
{

}

