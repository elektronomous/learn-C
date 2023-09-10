#include <iostream>
#include <string>

using namespace std;

int main(void) {
    string numbers("0123456789"), name("r2d2");
    // return the first found numbers in name
    string::size_type indexAfterFound = name.find_first_of(numbers);    // indexAfterFound = 1
}