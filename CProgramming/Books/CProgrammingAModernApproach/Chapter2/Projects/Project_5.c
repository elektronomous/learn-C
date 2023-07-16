#include <stdio.h>

// ¹²³⁴⁵⁶⁷⁸⁹⁰

int main(void) {
    int x;
    printf("Enter x's value: ");
    if (scanf("%d", &x) != 1)
        return 1;

    int polynomial = (3 * (x * x * x * x * x)) +        // => 3x²
                     (2 * (x * x * x * x)) -            // => 2x⁴
                     (5 * (x * x * x)) -                // => 5x³
                     (x * x) +                          // => x²
                     (7 * x) -                          // => 7x
                     6;
    
    printf("3x² + 2x⁴ - 5x³ - x² + 7x -6  = %d\n", polynomial);

    return 0;
}