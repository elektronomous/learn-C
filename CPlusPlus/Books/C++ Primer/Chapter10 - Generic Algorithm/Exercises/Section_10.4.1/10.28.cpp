#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <list>
#include <deque>


using namespace std;

void print(const int &i, const char &c) { 
    cout << i << c; 
}

int main(void) {
    vector<int> vects {1,2,3,4,5,6,7,8,9};
    vector<int> vint;
    list<int> lint;
    deque<int> deqint;

    cout << "Copy to the vint using back_inserter: " << endl;
    copy(vects.begin(), vects.end(), back_inserter(vint));
    // show value of vint
    cout << "Vint after back_inserter: " << endl;
    for_each(vint.begin(), vint.end(), bind(print, placeholders::_1, ' '));
    cout << endl;

    cout << "Copy to the deque using front_inserter: " << endl;
    copy(vects.begin(), vects.end(), front_inserter(deqint));
    // show value of deqint
    cout << "Deqint after front_inserter: " << endl;
    for_each(deqint.begin(), deqint.end(), bind(print, placeholders::_1, ' '));
    cout << endl;

    cout << "Copy to the lint using inserter: " << endl;
    copy(vects.begin(), vects.end(), inserter(lint, lint.begin()));
    // show value of lint
    cout << "Lint after inserter: " << endl;
    for_each(lint.begin(), lint.end(), bind(print, placeholders::_1, ' ' ));
    cout << endl;

    return 0;
}