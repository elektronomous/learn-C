#ifndef SCREEN_WINDOW_HPP
#define SCREEN_WINDOW_HPP

#include <vector>
#include <iostream>
#include <string>

/* 
Making a member function a friend requires careful structuring of our
programs to accommodate interdependencies among the declarations
and definitions. in this example, we must order our program as follows:
    read order:
    1.1 -> 1.2 -> 1.3 - 2.1 -> 2.2 -> 2.3
*/

// 1.3 Screen must be declared before clear can use the members of the Screen
class Screen;
class Window_mgr;

// 1.1 Define the window_mgr class
class Window_mgr {
    public:
        using ScreenIndex = std::vector<Screen>::size_type;
        // 1.2 which declare, but cannot define clear
        void clear(ScreenIndex);
        
        void print(void) const;
        void print(ScreenIndex i) const;
        void addScreen(Screen &s) {
            screens.push_back(s);
        }

    private:
        std::vector<Screen> screens;

};

// 2.1 Next define class Screen
class Screen {
    // Window_mgr members can access the private parts of this class
    // friend class Window_mgr;
    
    /*
    Rather than making the entire Window_mgr class a friend, Screen
    can instead speicify that only the clear member is allowed to access
    
    2.2 including a friend declaration for clear
    */ 
    friend void Window_mgr::clear(ScreenIndex);

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
        Screen &set(char);
        Screen &set(pos,pos,char);


        // const member function can change a mutable member
        void some_member(void) const {
            access_ctr++;
        }

        /*
        The call we intended:

            myScreen.display().set('#');
        
        logically, displaying a Screen doesn't change anything so we
        return reference to const of this object. But we intended to
        use it again, to change some state (change a data) we could 
        short it by overloading it and then create do_display() as
        the center of both overloaded function to call.
        = From this, if you have an idea of creating a method that
          will be called by whether nonconst or const object, you'll
          create two overloaded function and the center function.

        = This function will called by non-const object.
        */
        Screen &display(std::ostream &os) {
            do_display(os);
            return *this;
        }

        /* 
        = A const member function that return *this as reference
          should have a return type that is reference to const.
        = This function will be called by const object
        */
        const Screen &display(std::ostream &os) const {
            do_display(os);
            return *this;
        }
    private:
        pos cursor = 0;
        pos height = 0,
            width = 0;
        std::string contents;
    /*
    A mutable data member is never const, even when it is a member of const object        
    */
        mutable size_t access_ctr;

        /* CENTER FUNCTION */
        void do_display(std::ostream &os) const {
            os << contents;
        }
};

// we can specify inline at the function definition of the declaration
// of a function that dont have an inline declaration
inline Screen &Screen::move(pos r, pos c) {
    pos row = r * width;            // compute the row location
    cursor = row + c;               // move cursor to the column within that row
    return *this;
}

// we've declared this function as inline inside the class
char Screen::get(pos r, pos c) const {
    pos row = r * width;
    return contents[row + c];
}

inline Screen &Screen::set(char ch) {
    contents[cursor] = ch;
    return *this;
}

inline Screen &Screen::set(pos ht, pos wd, char ch) {
    contents[ht * width + wd] = ch;
    return *this;
}

// 2.3 define clear
void Window_mgr::clear(ScreenIndex i) {
    // s is a reference to the Screen we want to clear
    Screen &s = screens[i];
    // reset the contents of that Screen to all blanks
    s.contents = std::string(s.height * s.width, ' ');
    /* 
    Because Screen grants friendship to Window_mgr, all the members
    of Screen are accesible to the function in Window_mgr.
    */
}

void Window_mgr::print(ScreenIndex i) const {
    const Screen &s = screens[i];
    s.display(std::cout);
}

void Window_mgr::print(void) const {
    for (const Screen &s: screens)
        s.display(std::cout);
}

#endif