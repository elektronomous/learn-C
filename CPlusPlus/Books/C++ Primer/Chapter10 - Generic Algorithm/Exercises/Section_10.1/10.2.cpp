#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

int main(void) {
    list<int> lint {1,2,3,4,5,4,2,1,2,3,4,5,6,1,2,3,1,2,2,1,2};
    int val = 2;

    // how many value of 2 is present in list of int
    int howManyTwos = count(lint.cbegin(), lint.cend(), val);

    cout << "How many 2 in list: " << howManyTwos << " times." << endl;

    return 0;
}