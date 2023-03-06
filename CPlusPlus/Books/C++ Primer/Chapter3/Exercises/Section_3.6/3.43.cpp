#include <iostream>

int main(void) {
    int arr[3][5] = {
        {1,2,3,4,5},
        {6,7,8,9,10},
        {11,12,13,14,15}
    };

    // using for-range loop
    for (const int (&toArr)[5] : arr) {
        for (const int &el : toArr)
            std::cout << el << " ";
        std::cout << std::endl;
    }

    // using pointer
    for (int (*toArr)[5] = std::begin(arr); toArr != std::end(arr); toArr++){
        for (int *toEl = std::begin(*toArr); toEl != std::end(*toArr); toEl++)
            std::cout << *toEl << " ";
        std::cout << std::endl;
    }
}