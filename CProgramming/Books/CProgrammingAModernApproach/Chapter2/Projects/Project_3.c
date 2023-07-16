#include <stdio.h>

#define FRACTION (4.0f / 3.0f)
#define PHI (22.0f / 7.0f)


int main(void) {
    // declare variable
    float radius;

    printf("Enter the radius of the sphere: ");
    
    if (scanf("%f", &radius) != 1)
        return 1;
    
    // declare and initialize
    float volume = FRACTION / PHI * (radius * radius * radius);

    printf("The volume of sphere: %.2f\n", volume);

    return 0;
}