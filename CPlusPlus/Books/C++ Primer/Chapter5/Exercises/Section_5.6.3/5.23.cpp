#include <iostream>

using std::cin,
      std::cout,
      std::endl;


int main(void) {
    int numb1 = 0, numb2 = 0;

    std::cout << "Enter two number seperated by space: ";
    std::cin >> numb1 >> numb2;

    cout << numb1 / numb2 << endl;

    return 0;
}