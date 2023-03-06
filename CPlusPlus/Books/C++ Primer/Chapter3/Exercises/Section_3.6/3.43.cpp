#include <iostream>

<<<<<<< HEAD
=======
using std::cout,
      std::cin,
      std::endl;

>>>>>>> b5290e2b0cd458d3c79133d698174a643bc0b469
int main(void) {
    int arr[3][5] = {
        {1,2,3,4,5},
        {6,7,8,9,10},
        {11,12,13,14,15}
    };

<<<<<<< HEAD
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
=======
    // using for-range wihtout auto
    cout << "Using for-range loop: ";
    for (int (&toArr)[5] : arr) {
        for (int &el : toArr)
            cout << el << " ";
        cout << endl;
    }

    // using pointer
    for (int (*toArray)[5] = arr; toArray != arr + 3; toArray++) {
        for (int *toElement = *toArray; toElement != *toArray + 5; toElement++)
            cout << *toElement << " ";
        cout << endl;
    }

    // using subscript
    for (int row = 0; row < 3; row++){
        for (int col = 0; col < 5; col++)
            cout << arr[row][col] << " ";
        cout << endl;
    }

    return 0;
>>>>>>> b5290e2b0cd458d3c79133d698174a643bc0b469
}