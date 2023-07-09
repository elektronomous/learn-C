#include <iostream>

using std::cin,
      std::cout,
      std::endl;

int getAbs(int val) {
    return abs(val);
}


int main(void) {
    int num, result;

    cout << "Enter a number: ";
    cin >> num;

    result = abs(num);

    cout << "The absolute value of " << num << " is " << result << endl;

    return 0;
}