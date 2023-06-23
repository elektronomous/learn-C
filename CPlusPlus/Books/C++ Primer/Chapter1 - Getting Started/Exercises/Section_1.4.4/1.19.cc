#include <iostream>

int main(void) {
    int currVal = 0, val = 0;

    // get the first number for starting number
    while (std::cin >> currVal) {
        // show the output if the first number is less than the second number
        if (currVal > val){
            std::cout << currVal << " ";
            val = currVal;
        }
        
    }
}