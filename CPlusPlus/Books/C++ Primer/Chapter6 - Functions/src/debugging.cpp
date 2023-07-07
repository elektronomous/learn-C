#include <iostream>

using std::cin,
      std::cout,
      std::endl;

void whatAddressOf(int *pVal) {
    cout << "On whatAddressOf: " << pVal << endl;
}

void print(const int ia[10]) {
    for (size_t i = 0; i != 10; ++i)
        cout << ia[i] << endl;
}

int main(void) {
    int arr[10] = {0,1,2,3,4,5,6,7,8,9};

    print(arr);
    return 0;
}

/* 
On whatAddressOf: 0x7ffe3046d8b4
On main function: 0x7ffe3046d8b4

= pointer has value which is an address, if you pass argument
  the value you copy into the parameter is the address value

*/