/* Write a program containing the variables and assignments
   from the previous exercise. Print the variables before and after the
   assignments to check whether your preditions in the previous exercise
   were correct. If not, study the examples until you can convince yourself
   you know what led you to the wrong conclusion.
*/
#include <iostream>

int main(void) {
    int i = 0, &r = i;
    auto a = r;
    const int ci = i, &cr = ci;
    auto b = ci;
    auto c = cr;
    auto d = &i;
    auto e = &ci; 
    const auto f = ci;
    auto &g = ci;
    const auto &j = 42;
    auto k = ci, &l = i;
    auto &m = ci, *p = &ci;
    // auto &n = i, *p2 = &ci;

    // assignments from the previous exercise
    a = 42;
    b = 42;
    c = 42;
    // d = 42; illegal
    // e = 42; illegal
    // g = 42; illegal

    std::cout << a << b << c << std::endl;



    return 0;
}