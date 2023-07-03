#include <stdio.h>

int main(void) {
    // declare variable
    int height, length, width, volume, weight;

    printf("Enter height of box: ");
    scanf("%d", &height);

    printf("Enter length of the box: ");
    scanf("%d", &length);

    printf("Enter width of the box: ");
    scanf("%d", &width);

    // calculate volume
    volume = height * length * width;

    // calculate weight
    weight = (volume + 165) / 166;

    printf("Volume (cubic inces): %d\n", volume);
    printf("Dimensional weight (pounds): %d\n", weight);

    return 0;
}