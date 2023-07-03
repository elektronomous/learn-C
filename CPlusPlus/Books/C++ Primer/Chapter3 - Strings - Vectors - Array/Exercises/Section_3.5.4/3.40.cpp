#include <iostream>
#include <string.h>
#include <iterator>
#include <cstddef>  // ptrdiff_t


using std::cout,
      std::cin,
      std::endl,
      std::cbegin,
      std::cend;

int main(void) {
    const char str1[] = "Hello";
    const char str2[] = "There";
    
    // first you need to know the length of the str1 and str2
    // get length of str1
    ptrdiff_t str1_size = cend(str1) - cbegin(str1);
    ptrdiff_t str2_size = cend(str2) - cbegin(str2);
    // to concatenate the string we need to spare one element
    // to use as the null character
    const size_t total_size = str1_size + str2_size + 1;

    char str[total_size];

    cout << "Before concatenate: " << endl;
    cout << str1 << endl;
    cout << str2 << endl;

    cout << "After concatenate: " << endl;
    // using strcat
    cout << "Using strcat: ";
    strcat(str, str1);
    strcat(str, str2);
    cout << str << endl;

    // using strcpy
    // cout << "Using strcpy: ";
    // strcpy(str, str1);
    // strcpy(str, str2);
    // cout << str << endl;

    return 0;
}