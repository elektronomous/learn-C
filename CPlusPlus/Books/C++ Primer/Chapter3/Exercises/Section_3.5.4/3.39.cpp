#include <iostream>
#include <string.h>

using std::cout,
      std::cin,
      std::endl;

int main(void) {
    const char str1[] = "Hello";
    const char str2[] = "There";
    // const char str2 = "Hello";

    if (!strcmp(str1, str2))
        cout << "Both string are equal" << endl;
    else
        cout << "Both string are different" << endl;
    
    return 0;
}