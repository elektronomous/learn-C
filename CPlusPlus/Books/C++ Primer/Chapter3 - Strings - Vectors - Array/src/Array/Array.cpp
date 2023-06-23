#include <iostream>
#include <string>

using std::cout,
      std::cin,
      std::endl,
      std::string;

int main(void) {
    int arr[10];                    // ok
    int arr[] = {1,2,3,4,5};        // ok
    int a3[5] = {0,1,2};            // => {0, 1, 2, 0, 0}
    // int a5[2] = {0, 1, 2};       // error

    char a1[] = {'C', '+', '+'};        // list initialize without null
    char a2[] = {'C', '+', '+', '\0'};  // list initialized with null
    char a3[] = "C++";                  // null terminator added automatically
    // const char a4[6] = "Daniel";     // error: no space for the null;
}