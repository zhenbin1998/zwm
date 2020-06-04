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
            onEvent[event.type].event(this);
        }
}

void EventManager::buttonPress(EventManager *_eventsmanager)
{
    std::cout << "buttonPress" << std::endl;
}

void EventManager::buttonRelease(EventManager *_eventsmanager)
{

}

void EventManager::configureRequest(EventManager *_eventsmanager)
{

}

void EventManager::motionNotify(EventManager *_eventsmanager)
{

}

void EventManager::keyPress(EventManager *_eventsmanager)
{
    std::cout << "buttonPress" << std::endl;
    KeySym keysym = XkbKeycodeToKeysym(_eventsmanager->display,_eventsmanager->event.xkey.keycode, 0, 0);
    std::cout << keysym << std::endl;
}

void EventManager::mapRequest(EventManager *_eventsmanager)
{

}

void EventManager::destroyNotify(EventManager *_eventsmanager)
{

}

void EventManager::enterNotify(EventManager *_eventsmanager)
{

}

