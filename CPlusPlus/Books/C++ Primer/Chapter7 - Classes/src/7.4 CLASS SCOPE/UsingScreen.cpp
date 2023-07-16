#include <iostream>
#include "Screen.hpp"

using namespace std;

int main(void) {
    Screen::pos ht = 24, wd = 80;
    
    Screen scr(ht, wd, ' ');
    Screen *pScr = &scr;

    char c = scr.get();             // Fetches the get member from the object scr
    c = pScr->get();                // Fetches the get member from the object to which p points

    cout << "The character you get: " << c << "\n";

    return 0;
}