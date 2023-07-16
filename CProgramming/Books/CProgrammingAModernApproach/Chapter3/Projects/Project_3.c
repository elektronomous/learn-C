#include <stdio.h>

int main(void) {
    int GSIPrefix,
        groupIdentifier,
        publisherCode,
        itemNumber,
        checkDigit;

    printf("Enter ISBN: ");
    if (scanf("%d-%d-%d-%d-%d", 
              &GSIPrefix, &groupIdentifier, &publisherCode,
              &itemNumber, &checkDigit) < 1)
        return 1;

    printf("GSI prefix: %d\n", GSIPrefix);
    printf("Group identifier: %d\n", groupIdentifier);
    printf("Publisher code: %d\n", publisherCode);
    printf("Item number: %d\n", itemNumber);
    printf("Check digit: %d\n", checkDigit);

    return 0;
}