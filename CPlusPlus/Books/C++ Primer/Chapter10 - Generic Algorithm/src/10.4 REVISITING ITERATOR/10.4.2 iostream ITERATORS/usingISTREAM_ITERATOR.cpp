#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    vector<int> vint;
    istream_iterator<int> read_int(cin);    // read ints from cin
    istream_iterator<int> eof;              // istream end iterator

    while (read_int != eof)     // while there's valid input to read
        // postfix increment reads the stream and returns the old value of the iterator
        // we dereference that iterator to get the previous value read from the stream
        vint.push_back(*read_int++);
    
    cout << "The values that pushback to vector: " << endl;
    for_each(vint.begin(), vint.end(), [](const int &i) { cout << i << " ";});
    cout << endl;

    return 0;
}