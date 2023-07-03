#include <stdio.h>

int main(void) {
    printf("%.2d\n", 5);    // => 05
    printf("%.3d\n", 5);    // => 005

    printf("%.3e\n", 55.05); // => 5.505e+01
    printf("%.2f\n", 33.055); // => 33.05

    printf("%.5g\n", 33.5234);  // => 33.523
    printf("%.6g\n", 330.2344234);  // => 

    return 0;
}