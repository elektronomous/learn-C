#include <iostream>
#include <vector>

using namespace std;

int printVector(vector<int> vi, vector<int>::size_type i) {
    int result;

    if (i > 0) { 
        result = printVector(vi, i-1);
        cout << result << "\n";

#ifndef NDEBUG
        cout << "The vector size: " << vi.size() << endl;
#endif
    }

    return vi[i];
}

int main(void) {
    printVector({1,2,3,4,5}, 5);

    return 0;
}

/*

call                    function traces             value
({1,2,3,4,5}, 5)      ({1,2,3,4,5}, 4)               v[4]
({1,2,3,4,5}, 4)      ({1,2,3,4,5}, 3)               v[3]
({1,2,3,4,5}, 3)      ({1,2,3,4,5}, 2)               v[2]
({1,2,3,4,5}, 2)      ({1,2,3,4,5}, 1)               v[1]
({1,2,3,4,5}, 1)      ({1,2,3,4,5}, 0)               v[0]
({1,2,3,4,5}, 0)                                     


*/

