#include <stdio.h>

int main(void) {
    int num;

    printf("Enter three digit numbers: ");
    if (scanf("%d", &num) < 0)
        return 1;

    printf("The reversal is: %d%d%d\n", num % 10, (num / 10) % 10, num / 100);

    return 0;
}