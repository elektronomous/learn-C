#include <iostream>

int function(int a, int *b) {
    return (a > *b ? a : *b); 
}

// the type should an int instead of pointer to an int