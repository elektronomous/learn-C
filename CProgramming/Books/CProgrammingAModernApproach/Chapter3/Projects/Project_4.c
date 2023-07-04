#include <stdio.h>

int main(void) {
    int sectionOne,
        sectionTwo,
        sectionThree;

    printf("Enter phone number [(xxx) xxx-xxxx]: ");
    if (scanf("(%d) %d-%d", 
               &sectionOne, &sectionTwo, &sectionThree) < 1)
        return 1;
    
    printf("You entered %.3d.%.3d.%.4d\n", sectionOne, sectionTwo, sectionThree);

    return 0;
}