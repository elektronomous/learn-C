#include <stdio.h>

int main(void) {
    int num;
    
    printf("Enter a two-digit number: ");
    if (scanf("%d", &num) < 0)
        return 1;
    
    printf("The reversal is: %d%d\n", num % 10, num / 10);

    return 0;
}