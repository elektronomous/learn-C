#include <iostream>

using namespace std;

int main(void) {
    char *str1 = "Hello";
    char *str2 = "Hello";

    int *pStr1 = reinterpret_cast<int*>(str1);
    int *pStr2 = reinterpret_cast<int*>(str2);

    cout << pStr1 << endl;
    cout << pStr2 << endl;

    return 0;
}

/*
= When the char *str1 = "Hello" and char *str2 = "Hello", we get the address:
    str1 => 0x7fc318259004
    str2 => 0x7fc318259004

= When we change the char *str1 = "Hello" and char *str2 = "Hell", we get the address:
    str1 => 0x7fc318259004
    str2 => 0x7fc31825900a  

= This is could be the implementation of the OS when handling literal value like this.
  It puts the same literal value to the same address.
*/