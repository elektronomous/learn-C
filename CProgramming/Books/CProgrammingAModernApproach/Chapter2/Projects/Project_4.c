#include <stdio.h>

#define TAX (5.0/100.0)

// 1 dollar is equal to 100 cent

int main(void) {
    float amount;

    printf("Enter an amount: ");
    // libc warn you to always check the scanf return value
    if (scanf("%f", &amount) != 1)
        return 1;

    float taxesWithAmount = amount + (TAX * amount);

    printf("With tax added: %.2f\n", taxesWithAmount);

    return 0;
}