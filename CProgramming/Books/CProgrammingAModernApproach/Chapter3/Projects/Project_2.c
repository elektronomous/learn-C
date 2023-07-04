#include <stdio.h>

int main(void) {
    int itemNumber,
        day,
        month,
        year;
    
    float unitPrice;

    printf("Enter item number: ");
    if (scanf("%d", &itemNumber) < 0)
        return 1;

    printf("Enter unit price: ");
    if (scanf("%f", &unitPrice) < 0)
        return 1;
    
    printf("Enter purchase date (mm/dd/yyyy): ");
    if (scanf("%d/%d/%d", &month, &day, &year) < 0)
        return 1;
    
    printf("Item\tUnit\t\tPurchase\n\tPrice\t\tDate\n");
    printf("%-d\t$%7.2f\t%-.2d/%-.2d/%-d\n", itemNumber, unitPrice, day, month, year);

    return 0;
}