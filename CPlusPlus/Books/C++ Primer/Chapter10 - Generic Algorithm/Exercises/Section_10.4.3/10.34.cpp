#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

int main(void) {
    ostream_iterator<int> writeInt(cout, " ");
    vector<int> vint {1,2,3,4,5};

    cout << "Display vector in reverse order: " << endl;
    copy(vint.crbegin(), vint.crend(), writeInt);
    cout << endl;

    return 0;
}