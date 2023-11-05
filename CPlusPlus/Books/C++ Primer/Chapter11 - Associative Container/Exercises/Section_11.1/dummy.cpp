#include <iostream>
#include <algorithm>
#include <iterator>

using namespace std;

int main(void) {
    string name = "faza.akbar";
    string lowercase;
    copy(name.begin(), name.end(), back_inserter(lowercase));

    cout << lowercase << " " << endl;

    return 0;
}