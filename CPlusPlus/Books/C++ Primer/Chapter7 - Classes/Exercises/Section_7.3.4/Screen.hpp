#ifndef SCREEN_HPP
#define SCREEN_HPP

#include <vector>
#include <iostream>
#include "Window_mgr.hpp"

// 7.23
class Screen {
    // 7.32
    friend void Window_mgr::clear(ScreenIndex);

    public:
        typedef std::vector<char>::size_type pos;
        
        // 7.24
        Screen() = default;
        Screen(pos ht, pos wd):
               rows(ht), cols(wd), contents(ht * wd, ' ') { }
        Screen(pos ht, pos wd, char ch):
               rows(ht), cols(wd), contents(ht * wd, ch) { }
        
        // 7.27 
        Screen &move(pos x, pos y);
        Screen &set(char);
        Screen &display(std::ostream&);
        const Screen &display(std::ostream&) const;

    private:
        pos rows = 0,
            cols = 0,
            cursor = 0;
        std::vector<char> contents{' '};

        
        // 7.2      
        void do_display(std::ostream &os) const {
            for (const char &ch: contents)
                os << ch;
        }
};

// 7.27
Screen &Screen::move(pos x, pos y) {
    cursor = (y * cols) + x;
    return *this;
}

Screen &Screen::set(char ch) {
    contents[cursor] = ch;
    return *this;
}

Screen &Screen::display(std::ostream &os) {
    do_display(os);
    return *this;
}

const Screen &Screen::display(std::ostream &os) const {
    do_display(os);
    return *this;
}

void Window_mgr::clear(ScreenIndex i) {
    Screen &s = screens[i];
    s.contents = std::vector<char>(s.rows * s.cols, ' ');
}
#endif