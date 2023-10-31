#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>

using namespace std;

int main(void) {
    istream_iterator<int> read_int(cin), eof_int;
    vector<int> vint(read_int, eof_int);

    if (!vint.empty()) {
        cout << "The vector isn't empty: " << endl;
        for_each(vint.begin(), vint.end(), [] (const int &i) { cout << i << " ";});
        cout << endl;
    }

    return 0;

}