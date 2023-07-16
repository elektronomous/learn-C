#include <stdio.h>

int main(void) {
    int month, day, year;

    printf("Enter a date (mm/dd/yyyy): ");
    if (scanf("%d/%d/%d", &month, &day, &year) < 0)
        return 1;

    printf("You entered the date %d%.2d%.2d\n", year, month, day);

    return 0;
}