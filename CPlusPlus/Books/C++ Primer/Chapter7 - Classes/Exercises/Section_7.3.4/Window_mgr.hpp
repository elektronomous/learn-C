#ifndef WINDOWMGR_HPP
#define WINDOWMGR_HPP

#include <iostream>
#include <vector>

// 7.32
class Screen;

class Window_mgr {
    private:
        std::vector<Screen> screens;
    
    public:
        using ScreenIndex = std::vector<Screen>::size_type;
        void clear(ScreenIndex);
};
#endif