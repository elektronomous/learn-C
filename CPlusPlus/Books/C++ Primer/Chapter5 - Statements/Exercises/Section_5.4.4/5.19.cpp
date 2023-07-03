#include <iostream>
#include <string>

using std::cin,
      std::cout,
      std::endl,
      std::string;

int main(void) {
    string str1, str2, rsp;

    do {
        cout << "Enter two strings seperated by spaces: ";
        cin >> str1 >> str2;

        if (!str1.empty() && !str2.empty()) {
            if (str1 > str2)
                cout << "the first string is longest than the second one." << endl;
            else 
                cout << "the second string is longest than the first one." << endl;
        }

        cout << "Continued(Y/N): ";
        cin >> rsp;

    } while (!rsp.empty() && (rsp[0] != 'n' || rsp[0] != 'N'));

    return 0;
}