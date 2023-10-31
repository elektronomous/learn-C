#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

int main(void) {
    vector<int> vint {1,2,3,4,5};
    vector<int> vint2 {1,2,3,4,5};
    vector<int> vint3 {1,2,3,4,5};

    ostream_iterator<int> out_int(cout);
    ostream_iterator<int> out_int2(cout, " ");
    ostream_iterator<int> out_int3(cout, "-");

    cout << "Vint: " << endl;
    for (const int &i: vint)
        *out_int++ = i;
    cout << endl;

    cout << "Vint2: " << endl;
    for (const int &i: vint2)
    /*
        It is worth noting that we can omit the dereference and the increment when we
        assign to out_iter
    */
        out_int2 = i;
    cout << endl;

    /* more easy */
    copy(vint.begin(), vint.end(), out_int3);
    cout << endl;

    return 0;
}