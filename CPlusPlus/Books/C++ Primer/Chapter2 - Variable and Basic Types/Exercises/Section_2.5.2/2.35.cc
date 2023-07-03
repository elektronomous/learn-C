/* Determine the types deduced in each of the following
   definitions. Once you've figured out the types, write a program to see
   whether you were correct.

   const int i = 42;
   auto j = i;          // int j = 42;
   const auto &k = i;   // const reference to reference to const
   auto *p = &i;        // pointer to const int.
   const auto j2 = i, &k2 = i;   // const int, const reference to const int 
*/

#include <iostream>

int main(void) {
    const int i = 42;
    auto j = i;
    const auto &k = i;
    auto *p = &i;
    const auto j2 = i, &k2 = i;

    return 0; 
}