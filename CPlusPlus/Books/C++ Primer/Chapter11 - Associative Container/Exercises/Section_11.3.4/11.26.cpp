#include <iostream>
#include <map>
#include <array>

using namespace std;

int main(void) {
    // all type can be used to subscript the map
    // the subscript operator return a mapped_type object
    map<array<int, 3>, string> arrMtoStr {{{1,2,3}, "hello"}, {{3,2,1}, "there"}};

    cout << arrMtoStr[array<int, 3>{1,2,3}] << endl;

    return 0;
}