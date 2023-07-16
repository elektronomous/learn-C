#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    vector<char> chs(10, ' ');

    for (const char &ch: chs)
        if (isspace(ch))
            cout << "Yes, it's space\n";
    
    return 0;
}