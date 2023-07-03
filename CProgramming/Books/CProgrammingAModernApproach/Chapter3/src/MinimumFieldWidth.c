#include <stdio.h>

int main(void) {
    printf("|%4d|\n", 123);
    printf("|%-4d|\n", 123);

    printf("|%7d|\n", 123);
    printf("|%-8d|\n", 123);

    return 0;
}