#include <iostream>
#include <string>

using std::cout,
      std::cin,
      std::endl,
      std::string;

int main(void) {
    unsigned max_number = 0,
             counter = 0;

    string str,
           track_str,
           max_str;
    
    while (cin >> str) {
        if (cin >> track_str) {
            if (track_str == str)
                counter++;
        }
    }
}