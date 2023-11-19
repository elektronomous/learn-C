#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int>* createVint(void) {
    return new vector<int>();
}

void fillVint(vector<int> *v) {
    int n;
    while (cin >> n)
        v->push_back(n);
}

void printVint(const vector<int> *v) {
    for_each(cbegin(*v), cend(*v), [](const int &v) { cout << v << " "; });
    cout << endl;
}

int main(void) {
    vector<int> *pVec = createVint();
    // fill the values
    fillVint(pVec);
    // show the value
    printVint(pVec);

    delete pVec;

    return 0;
}