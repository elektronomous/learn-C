#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>

using namespace std;

int main(void) {

    cout << "Enter numbers seperated by space: " << flush;
    istream_iterator<int> readInt(cin), eof_readInt;
    ostream_iterator<int> writeInt(cout, " ");
    vector<int> vint(readInt, eof_readInt);
    
    cout << "Sort the numbers you've entered: " << endl;
    sort(vint.begin(), vint.end());

    cout << "The numbers you've entered sorted: " << endl;
    unique_copy(vint.cbegin(), vint.cend(), writeInt);
    cout << endl;

    return 0;
}