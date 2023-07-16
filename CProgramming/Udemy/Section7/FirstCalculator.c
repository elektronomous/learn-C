#include <stdio.h>

int main(void) {
    printf("%d + %d = %d \n", 5, 2, 5 + 2);
    printf("%d - %d = %d \n", 5, 2, 5 - 2);
    printf("%d * %d = %d \n", 5, 2, 5 * 2);
    printf("%d / %d = %d \n", 5, 2, 5 / 2);     // truncate the part of the decimal point
    printf("%d %% %d = %d \n", 5, 2, 5 % 2);    // Taking the remainder

    return 0;
}