#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

int main(void) {
    vector<int> vint {0,1,2,3,4,5,6,7,8,9};
    list<int> lint(10);

    vector<int>::reverse_iterator sevenPos = vint.rbegin() + 3,
                                  threePos = vint.rend() - 3;

    cout << "Copy to the list" << endl;
    copy(sevenPos, threePos, lint.begin());

    cout << "The value of list: " << endl;
    for (const int &i: lint)
        cout << i << " ";
    cout << endl;

    return 0;
}