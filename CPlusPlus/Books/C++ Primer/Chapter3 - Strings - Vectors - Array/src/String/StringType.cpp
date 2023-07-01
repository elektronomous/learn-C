#include <iostream>
#include <string>


int main(void) {
    std::string str1;           // empty string
    std::string str2 = str1;    // copy initialization => copy of str1
    std::string s3 = "hiya";    // copy initialization => copy of string literal
    std::string str3("hiya");   // direct initialization
    std::string s4(10, 'c');    // direct initialization => 'cccccccccc';
    const char *cStyleString = s3.c_str();      // get the string as the C-style string

    // getline => read until we encounter the enter
    std::getline(std::cin, str1);
    std::cout << "str1: " << str1 << std::endl;

    // empty => return true or false indicating whether string is empty
    std::cout << str1.empty() << std::endl;     // 0 => false

    // size => returns the length of a string
    // to store the size
    std::string::size_type str3Size = str3.size();
    std::cout << str3Size << std::endl;      // => 4

    // if ("hellodssf" < "there") {
    //     std::cout << "True" << std::endl;
    // }

    // you can replace the string`
    str1 = "Hello There";
    std::cout << "str1: " << str1 << std::endl;
    // or
    str1 = str3;
    std::cout << "str1: " << str1 << std::endl;

    // you can concatenate string
    str3 += " hiya hiya";
    std::cout << "str3: " << str3 + " hiya" << std::endl;

    s4 = " " + s4;
    std::cout << s4 << std::endl;
    
    std::cout << "C-style string: " << cStyleString << std::endl;

    return 0;
}