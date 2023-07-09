#include <iostream>

using std::cin,
      std::cout,
      std::endl;

// function definion
void print(const int []);
// or void print(const int *);
// or void print(const int[10])

void print(const int arr[]) {
    // if you wanna know the bound of you array
    // you should create at least two parameters
    cout << "The first element: " << arr[0] << endl;
    cout << "The second element: " << arr[1] << endl;
    cout << "The third element: " << arr[2] << endl;
}

int main(void) {
    int j[5] = {1,2,3,4,5};

    print(j);       // j is converted automatically to an int* points to j[0]

    return 0;
}