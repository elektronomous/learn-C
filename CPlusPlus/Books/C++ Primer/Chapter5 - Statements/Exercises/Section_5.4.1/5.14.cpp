#include <iostream>
#include <string>

using std::cout,
      std::cin,
      std::endl,
      std::string;

int main(void) {
    unsigned max_number = 0,
             counter = 1;

    string str,
           track_str,
           max_str;
    
    if (cin >> str) {
        while (cin >> track_str) {
            if (str == track_str)
                counter++;
            else {
                counter = 1;
                str = track_str;
            }

            if (counter > max_number) {
                max_number = counter;
                max_str = str;
            }
        }
    }

    if (max_number) 
        cout << "The word \"" << max_str << "\" is occured " << max_number << " times" << endl;
        
    return 0;
}