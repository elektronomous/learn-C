#include <stdio.h>

// ¹²³⁴⁵⁶⁷⁸⁹⁰

int main(void) {
    int x;
    printf("Enter x's value: ");
    if (scanf("%d", &x) != 1)
        return 1;
    
    int polynomial = ((((3*x + 2) * x - 5) * x - 1) * x + 7) * x - 6;

    printf("((((3x + 2)x - 5)x - 1)x + 7)x - 6 = %d\n", polynomial);

    return 0;
}

