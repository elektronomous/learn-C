/* 
As an example, we’ll write a function to compare the length of two strings.
Because strings can be long, we’d like to avoid copying them, so we’ll make our
parameters references. Because comparing two strings does not involve changing
the strings, we’ll make the parameters references to const

*/

#include <iostream>
#include <string>

using std::cin,
      std::cout,
      std::endl,
      std::string;

bool isShorter(const string &str1, const string &str2) {
    return str1.size() < str2.size();
    // you can't modify the str1 or str2 because it
    // defined by the keyword const.
}