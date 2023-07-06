#include <iostream>

using std::cin,
      std::cout,
      std::endl;

int fact(int val) {
    int result = 1;

    while(val > 1)
        result *= val--;
    
    return result;
}

int main(void) {
    int num, result;

    cout << "Enter a number: ";
    cin >> num;

    result = fact(num);

    cout << num << "! : " << result << endl;

    return 0;
}