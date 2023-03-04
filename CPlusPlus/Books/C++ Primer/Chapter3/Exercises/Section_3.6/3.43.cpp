#include <iostream>

using std::cout,
      std::cin,
      std::endl;

int main(void) {
    int arr[3][5] = {
        {1,2,3,4,5},
        {6,7,8,9,10},
        {11,12,13,14,15}
    };

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
}