#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

int main(void) {
    vector<int> vint {1,2,3,4,5};
    reverse_copy(vint.begin(), vint.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    return 0;
}