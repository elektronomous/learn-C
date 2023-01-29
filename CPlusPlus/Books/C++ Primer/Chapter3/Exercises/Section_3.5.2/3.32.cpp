#include <iostream>
#include <vector>

using   std::cin,
        std::cout,
        std::endl,
        std::vector;

int main(void) {
    const size_t arr_size = 10;
    int arr[arr_size];
    int arr2[arr_size];

    // first initialize the arr 
    for (size_t i = 0; i < arr_size; i++) 
        arr[i] = i;
    // copy arr to arr2
    for (size_t i = 0; i < arr_size; i++) 
        arr2[i] = arr[i];
    
    // show result
    cout << "First array: ";
    for (int &v : arr)
        cout << v << " ";
    cout << endl;

    cout << "Second array: ";
    for (int &v : arr2)
        cout << v << " ";
    cout << endl;

    return 0;
}