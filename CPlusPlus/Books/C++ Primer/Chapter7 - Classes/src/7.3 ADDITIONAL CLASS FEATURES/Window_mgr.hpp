#ifndef WINDOW_MGR_HPP
#define WINDOW_MGR_HPP

#include <vector>
#include "Screen.hpp"

class Window_mgr {
    private:
        std::vector<Screen> screens {Screen(20, 80, ' ')};
};

#endif