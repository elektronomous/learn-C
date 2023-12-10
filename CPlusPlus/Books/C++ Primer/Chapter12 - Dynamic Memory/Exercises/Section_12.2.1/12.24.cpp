#include <iostream>
#include <memory>
#include <cstring>

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

            if (allocChar != nullptr){
                // copy the input to the allocation char
                strncpy(allocChar, inputStr.c_str(), inputStr.size());
                // then show the result
                cout << "After allocating, we show the result: " << allocChar << endl;

                // delete the memory
                delete[] allocChar;
                allocChar = nullptr;
            }
        }
    }

    return 0;
}

/* This program handles the varying input size by get the size of the input first,
   then store the size into inputSz. This inputSz will be the size of the allocated
   array later.
*/