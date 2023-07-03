#include <iostream>

using std::cout,
      std::cin,
      std::endl;

typedef int int_array[5];
// using int_array = int[4];

int main(void) {
    int arr[3][5] = {
        {1,2,3,4,5},
        {6,7,8,9,10},
        {11,12,13,14,15}
    };

    for (int_array &toArr : arr) {
        for (int &el : toArr)
            cout << el << " ";
        cout << endl;
    }

    for (int_array *toArr = arr; toArr != arr+3; toArr++) {
        for (int *el = *toArr; el != *toArr + 5; el++)
            cout << *el << " ";
        cout << endl;
    }

    return 0;
}