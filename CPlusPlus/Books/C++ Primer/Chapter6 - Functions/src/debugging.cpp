#include <iostream>
#include <string>

using std::cin,
      std::cout,
      std::endl,
      std::string;

int main(void) {
  const char *str1 = "Hello There";
  string str2 = "or Hello World";

  str2 += str1;

  cout << str2 << endl;

  return 0;
}

/* 
On whatAddressOf: 0x7ffe3046d8b4
On main function: 0x7ffe3046d8b4

= pointer has value which is an address, if you pass argument
  the value you copy into the parameter is the address value

*/