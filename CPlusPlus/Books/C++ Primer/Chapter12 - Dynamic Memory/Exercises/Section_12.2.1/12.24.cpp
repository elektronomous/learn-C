#include <iostream>
#include <memory>

using namespace std;

int main(void) {
    string inputStr;
    size_t inputSz = 0;
    while (cin >> inputStr) {
        // get the size
        inputSz = inputStr.size();

        if (inputSz) {
            // allocate the char of this size
            char *allocChar = new char[inputSz];
            // copy the input to the allocation char
            strncpy(allocChar, inputStr.c_str(), inputStr.size());

            // then show the result
            cout << "After allocating, we show the result: " << allocChar << endl;
        }
    }
}