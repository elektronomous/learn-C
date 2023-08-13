#include <iostream>
#include <vector>
#include <list>

using namespace std;

bool veclistCompare(const vector<int> &v, const list<int> &l) {
    vector<int> copyList(l.begin(), l.end());

    return v == copyList;
}

int main(void) {
    vector<int> vint {1,2,3,4};
    list<int> lint {1,2,3};

    if (veclistCompare(vint, lint))
        cout << "The vector and the list are the same" << endl;
    else
        cout << "The vector and the list aren't the same" << endl;
    
    return 0;
}