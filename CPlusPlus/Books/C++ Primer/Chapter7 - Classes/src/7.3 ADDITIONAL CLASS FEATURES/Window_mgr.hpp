#ifndef WINDOW_MGR_HPP
#define WINDOW_MGR_HPP

#include <vector>
#include <string>

class Screen;
class Window_mgr {
    public:
        using ScreenIndex = std::vector<Screen>::size_type;
        void clear(ScreenIndex);
        void addScreen(Screen &s) {
            screens.push_back(s);
        }

    private:
        std::vector<Screen> screens {Screen(20, 80, ' ')};

};

#endif