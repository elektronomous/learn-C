#include <iostream>

using std::cin,
      std::cout,
      std::endl;

void whatAddressOf(int *pVal) {
    cout << "On whatAddressOf: " << pVal << endl;
}

int main(void) {
    int j = 5, *pJ = &j;
    
    whatAddressOf(pJ);  // copy address contain in pJ to pVal
    cout << "On main function: " << pJ << endl;
    return 0;
}

/* 
On whatAddressOf: 0x7ffe3046d8b4
On main function: 0x7ffe3046d8b4

= pointer has value which is an address, if you pass argument
  the value you copy into the parameter is the address value

*/