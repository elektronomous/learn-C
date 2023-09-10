#include <iostream>
#include <string>

using namespace std;

int main(void) {
    string str = "Hello World";
    string str2 = "-----";
    const char *cp = "Jupiter, Uranus";

    str.insert(str.size(), 5, '!');     // insert five '!' at the end of the string
    str.insert(6, cp + 9);              // insert Uranus at middle of str; str = "Hello UranusWorld";
    str.insert(12, " ");                // insert space at the middle of str; str = "Hello Uranus World!!"
    
    cout << "The string after insert: " << str << endl;     // => "Hello Uranus World!!!!!"

    str.insert(0, str2);                        // copy str2 before position 0; "-----Hello Uranus World!!!!!"
    str.insert(6, str2,    0, str2.size());    // insert str2.size() characters from str2, starting from str2[0]
                /*|_str[0]_| */                            // before s[6]

    return 0;
}