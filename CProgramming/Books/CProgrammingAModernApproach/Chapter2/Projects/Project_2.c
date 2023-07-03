#include <stdio.h>

#define FRACTION (4.0f / 3.0f)
#define PHI (22.0f / 7.0f)


int main(void) {
    float radius = 10.0f;
    float volume = FRACTION / PHI * (radius * radius * radius);

    printf("The volume of sphere: %.2f\n", volume);

    return 0;
}