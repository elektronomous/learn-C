#include <iostream>

int main(void) {
    // currVal is the number we're counting; we'll read new values into val
    int currVal = 0, val = 0;

    // read the first number and we have data to process
    if (std::cin >> currVal) { 
        int cnt = 1;            // store the count for the current value we're counting
        
        while (std::cin >> val) {   // read the remaining numbers
            if (val == currVal)     // if the values are the same
                cnt++;              // add 1 to counter
            else {                  // otherwise
                std::cout << currVal << " occurs "
                          << cnt << " times" << std::endl;

                cnt = 1;            // reset the counter
                currVal = val;      // change the value to the
            }
        }
        std::cout << currVal << " occurs "
                  << cnt << " times " << std::endl;
    }

    return 0;
}