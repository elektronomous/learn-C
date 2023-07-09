#include <iostream>

using std::cin,
      std::cout,
      std::endl;

int fact(int val) { // (2) called function begin executed
    int ret = 1;

    while (val > 1)
        ret *= val--;
    return ret;
}

int main(void) {
    int j = fact(5);    // (1) calling function is suspended

    cout << "5! is : " << j << endl;

    return 0;
}