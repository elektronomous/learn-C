#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>

using namespace std;

shared_ptr<vector<int>> createVint(void) {
    return make_shared<vector<int>>();
}

void fillVint(shared_ptr<vector<int>> &v) {
    int n;
    while (cin >> n)
        v->push_back(n);
}

void printVint(const shared_ptr<vector<int>> &v) {
    for_each(cbegin(*v), cend(*v), [](const int &v) { cout << v << " "; });
    cout << endl;
}

int main(void) {
    shared_ptr<vector<int>> pVec = createVint();
    // fill the values
    fillVint(pVec);
    // show the value
    printVint(pVec);

    return 0;
}