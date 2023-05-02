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

    for (auto &toArr : arr) {
        for (auto &el : toArr)
            cout << el << " ";
        cout << endl;
    }

    for (auto toArr = arr; toArr != arr + 3; toArr++) {
        for (auto el = *toArr; el != *toArr + 5; el++)
            cout << *el << " ";
        cout << endl;
    }

    return 0;
}