/* Write code to change the value of a pointer. Write code to change the value to which
   the pointer points

*/
#include <iostream>

int main(void) {
    int i = 10;
    int *pi = nullptr;

    // change the value of pointer to i object
    pi = &i;
    std::cout << *pi << std::endl;
    // change the value to which the pointer points
    *pi = 20;

    std::cout << *pi << std::endl;
    // proof it

}