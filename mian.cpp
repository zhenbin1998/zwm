#include <iostream>
#include "WindowManager.hpp"

int main()
{
    std::unique_ptr<WindowManager> windowManager = WindowManager::Create();
    if(!windowManager)
    {
        std::cerr << "Failed to Initlalize window anager." << std::endl;
        return 0;
    }

    windowManager->Run();

    return 0;
}