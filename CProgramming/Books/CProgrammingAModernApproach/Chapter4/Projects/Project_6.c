#include <stdio.h>

int main(void) {
    int n1, n2, n3, n4, n5, 
        n6, n7, n8, n9, n10, 
        n11, n12,
        first_total,
        second_total,
        check_digit;

    // EAN => European Article Number using 13-digits
    printf("Enter the first 12 digits of an EAN: ");
    if (scanf("%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d", 
              &n1, &n2, &n3, &n4, &n5, &n6, 
              &n7, &n8, &n9, &n10, &n11, &n12) < 0)
        return 1;
    
    first_total = n2 + n4 + n6 + n8 + n10 + n12;
    second_total = n1 + n3 + n5 + n7 + n9 + n11;

    first_total = (first_total * 3) + second_total;

    check_digit = (9 - (first_total - 1) % 10);

    printf("Check digit: %d\n", check_digit);

    return 0;

}