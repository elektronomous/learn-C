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
/* 

=> result
1 2 3 4 5 6 7 8 9
1 2 3 4 5 6 7 8 9
1 occurs 1 times
2 occurs 1 times
3 occurs 1 times
4 occurs 1 times
5 occurs 1 times
6 occurs 1 times
7 occurs 1 times
8 occurs 1 times
^D
9 occurs 1 time


*/