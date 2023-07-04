#include <stdio.h>

int main(void) {
    printf("%12.5e\n", 30.253);
    printf("%.4f\n", 83.162);
    printf("%-6.2g|\n", .0000009979);
    printf("%-8.1e\n",32.2533);
    printf("%6.0f\n", 32.255);

    printf("Item\tUnit\tPurchase\n\tPrice\tDate\n");

    return 0;
}