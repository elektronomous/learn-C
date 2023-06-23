#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;

typedef vector<int> vint;
typedef vector<string> vstr;

int main(void) {
    vint vi {1,2,3,4};

    // get the length of the vi
    cout << vi.cend() - vi.cbegin() << endl;
    // get the mid length of the vi
    cout << (vi.cend() - vi.cbegin())/2 << endl;

    return 0;
}