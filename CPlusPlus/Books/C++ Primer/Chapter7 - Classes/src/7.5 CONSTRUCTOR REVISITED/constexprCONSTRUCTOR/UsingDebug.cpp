#include <iostream>
#include "Debug.hpp"

using namespace std;

int main(void) {
    /* 
    A constexpr constructor is used to generate objects that are constexpr and for
    parameters or return types in constexpr functions
    */
    constexpr Debug io_sub(false, true, false);     // debugging IO

    if (io_sub.any())       // equivalent to if (true)
        cerr << "print appropriate error messages" << endl;

    constexpr Debug prod(false);                    // no debugging during production
    if (prod.any())
        cerr << "print an error message" << endl;

    return 0;

}