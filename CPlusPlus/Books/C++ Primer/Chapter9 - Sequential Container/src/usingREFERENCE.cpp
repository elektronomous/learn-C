#include <vector>
#include <iostream>

using namespace std;

int main(void) {
    vector<int> vint {1,2,3,4,5};
    int x = 20;
    vector<int>::reference toX = x;

    cout << toX << endl;

    return 0;
}