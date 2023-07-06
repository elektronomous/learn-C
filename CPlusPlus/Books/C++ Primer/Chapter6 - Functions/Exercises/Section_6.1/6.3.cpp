#include <iostream>

using std::cin,
      std::cout,
      std::endl;

int fact(int val) {
    int result = 1;

    while (val > 1)
        result *= val--;
    
    return result;
}

int main(void) {
    int j = fact(5);

    cout << "5! : " << j << endl;

    return 0;
}