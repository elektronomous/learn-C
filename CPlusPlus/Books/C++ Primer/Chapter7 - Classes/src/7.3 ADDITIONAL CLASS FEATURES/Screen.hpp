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

#endif