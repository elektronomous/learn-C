#include <iostream>

int factorial(int val) {
    if (val > 1)
        return factorial(val-1) * val;
        // the function will call first, the return is
        // execute after the function is done
    
    return 1;
}