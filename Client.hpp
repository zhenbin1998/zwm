#ifndef CLIENT_HPP
#define CLIENT_HPP

#include "include.hpp"

class Client
{
private:
    Window win;
    struct position
    {
        uint x;
        uint y;
    };
    uint height;
    uint width;
    
public:
    Client(/* args */);
    ~Client();
};


#endif //CLIENT_HPP