#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int main(void) {
    deque<int> deqint {1,2,3,4};

    deque<int>::iterator middleDeqint = deqint.begin() + (deqint.size()/2);
    int &secondDeqint = deqint.at(1);

    deqint.insert(deqint.begin() + 1, {5, 6, 7});

    cout << "Is middleDeqint valid: " << *middleDeqint << endl;
    cout << "secondDeqint is it valid: " << secondDeqint << endl;
    cout << "deqint contains: ";
    for (const int &val: deqint)
        cout << val << " ";
    cout << endl;

    return 0;
}