#ifndef SCREEN_HPP
#define SCREEN_HPP

#include <string>

class Screen {
    public:
    /* 
    members that define types must appear before they are used. As a result,
    type members usually appear at the beginning of the class
    */
        typedef std::string::size_type pos;
    /*
    or
        using pos = std::string::size_type;

    Users of Screen shouldn't know that Screen uses a string to hold its data.
    By defining pos as a public member, we can hide this detail of how Screen
    is implemented.
    */

    Screen() = default;
    Screen(pos ht, pos wd, char c):
           height(ht), width(wd), contents(ht * wd, c) { }
    
    char get(void) const { return contents[cursor]; }           // get the character at the cursor
    inline char get(pos ht, pos wd) const;                      // explicitly inline
    Screen &move(pos r, pos c);                                 // can be made inline later.
    private:
        pos cursor = 0;
        pos height = 0,
            widht = 0;
        std::string contents;
};

#endif