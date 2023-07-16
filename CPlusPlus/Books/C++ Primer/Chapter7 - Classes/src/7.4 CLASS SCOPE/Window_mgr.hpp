#ifndef WINDOW_MGR_HPP
#define WINDOW_MGR_HPP

#include <vector>
#include <string>

class Screen;
class Window_mgr {
    public:
        using ScreenIndex = std::vector<Screen>::size_type;
        void clear(ScreenIndex);
        ScreenIndex addScreen(const Screen &s);

    private:
        std::vector<Screen> screens;

};

// return type is seen before we're in the scope of Window_mgr.
Window_mgr::ScreenIndex Window_mgr::addScreen(const Screen &s) {
    screens.push_back(s);           // we're copything the const object.
    return screens.size() - 1;
}

#endif