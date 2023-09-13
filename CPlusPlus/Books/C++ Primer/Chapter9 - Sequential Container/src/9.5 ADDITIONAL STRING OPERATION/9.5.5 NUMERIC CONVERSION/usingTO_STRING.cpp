#include <iostream>
#include <string>

using namespace std;

int main(void) {
    int numbers = 10;
    string numbers_to_string = to_string(numbers);
    string another_numbers_to_string = to_string(10 + 30 + 50);
    cout << numbers_to_string << endl;
    cout << another_numbers_to_string << endl;

    return 0;
}