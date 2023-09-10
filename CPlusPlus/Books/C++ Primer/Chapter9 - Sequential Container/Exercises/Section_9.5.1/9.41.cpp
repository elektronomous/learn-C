#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    vector<char> vchr {'a','b','c','d','f'};
    string str(vchr.begin(), vchr.end());

    cout << "The string copied from vector char: " << str << endl;

    return 0;
}