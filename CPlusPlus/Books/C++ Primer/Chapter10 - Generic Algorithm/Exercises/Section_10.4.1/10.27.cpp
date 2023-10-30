#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <string>

using namespace std;

int main(void) {
    vector<int> vint {1,2,3,4,4,5,5,6,6,7};
    list<int> lint;

    cout << "Copy vint to lint: " << endl;
    unique_copy(vint.cbegin(), vint.cend(), back_inserter(lint));

    cout << "Show lint value: " << endl;
    for_each(lint.begin(), lint.end(), [](const int &i) { cout << i << " "; });
    cout << endl;

    return 0;

}