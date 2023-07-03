#include <iostream>

using std::endl,
      std::cin,
      std::cout;

int main(void) {
    const size_t arr_size = 20;
    int arr[arr_size];

    for (size_t i = 0; i < arr_size; i++ )
        arr[i] = i;
    
    // show the result
    for (int &v : arr)
        cout << v << " ";
    cout << endl;
}