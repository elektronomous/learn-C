#include "Chapter6.hpp"

// (2) the definition of our function is here before it use
//     on the factMain.cpp

int fact(int val) {
    int result = 1;

    while (val > 1)
        result *= val--;
    
    return result;
}