#include <iostream>

using std::cin,
      std::cout,
      std::endl;

void printOne(const int *arr) {
    cout << "The first element of array: " << *arr << endl;
}

void printTwo(const int arr[]) {
    cout << "The first element of array: " << arr[0] << endl;
}

void printThree(const int arr[2]) {
    cout << "The first element of array: " << arr[0] << endl;
}

int main(void) {
    int i = 0,
        j[2] = {0, 1};
    
    cout << "First function: " << endl;
    printOne(&i);
    printOne(j);

    cout << "Second function: " << endl;
    printTwo(&i);
    printTwo(j);

    cout << "Three function: " << endl;
    printThree(&i);
    printThree(j);

    return 0;
}