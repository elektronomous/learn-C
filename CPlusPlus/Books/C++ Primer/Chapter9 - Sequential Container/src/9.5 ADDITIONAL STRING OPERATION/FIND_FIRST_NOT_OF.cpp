#include <iostream>
#include <string>

using namespace std;

int main(void) {
    string code("12343p43"), numbers("0123456789");   
    // index after found
    string::size_type indexAfterFound = code.find_first_not_of(numbers);    // indexAfterFound = 6
}