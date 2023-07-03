#include <stdio.h>

int main(void) {
    // declare variables
    int height, length, width, volume;

    // initialize variables
    height = 8;
    length = 12;
    width = 10;
    volume = height * length * width;

    printf("Dimensions: %dx%dx%d\n", height, length, width);
    printf("Volumes (cubic inches): %d\n", volume);
    printf("Dimesional weight (pounds): %d\n", (volume + 165) / 166);

    return 0;
}