#include <iostream>
#include <string>

using std::cin,
      std::cout,
      std::endl,
      std::string;

string (&function(void))[10];

int main(void) {
  int arr[] = {1,2,3,4,5};
  decltype(arr) anotherArr = {1,2,3,4,5};

  cout << "On the arr[0]: " << arr[0] << " and the anotherArr[0]: " << anotherArr[0] << endl;

  return 0;
}
/* 
On whatAddressOf: 0x7ffe3046d8b4
On main function: 0x7ffe3046d8b4

= pointer has value which is an address, if you pass argument
  the value you copy into the parameter is the address value

*/