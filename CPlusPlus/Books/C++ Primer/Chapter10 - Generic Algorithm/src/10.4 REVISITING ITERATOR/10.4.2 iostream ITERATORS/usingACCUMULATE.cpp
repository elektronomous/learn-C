#include <iostream>
#include <numeric>
#include <iterator>

using namespace std;

int main(void) {
    istream_iterator<int> read_int(cin), eof_int;
    if (read_int == eof_int)
        cout << "Empty values entered by user." << endl;
    else {
        cout << "Contain some values: " << endl;
        /* 
           you can use it like this: 
        for_each(read_int, eof_int, [](const int &i) { cout << i << " "; });

            or you can use it like this:
        */
        cout << accumulate(read_int, eof_int, 0) << endl;
    }

    return 0;
}