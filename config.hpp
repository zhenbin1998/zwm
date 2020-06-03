#ifndef CONFIG_HPP
#define CONFIG_HPP

#define MOD Mod4Mask
#include <X11/keysym.h>

void run(const XArg arg);
const char* xclock[]    = {"xclock",             0};
XKey key[] = {
    {MOD,  XK_c ,  run,  {.com = xclock}}

};


#endif //CONFIG_HPP