#include <iostream>
#include <string>
#include <cassert>

using std::cin,
      std::cout,
      std::endl,
      std::string;

string (&function(void))[10];

int main(void) {
    string s, shought = "hello";
    assert(cin);
    

  return 0;
}
/* 
On whatAddressOf: 0x7ffe3046d8b4
On main function: 0x7ffe3046d8b4

= pointer has value which is an address, if you pass argument
  the value you copy into the parameter is the address value

*/