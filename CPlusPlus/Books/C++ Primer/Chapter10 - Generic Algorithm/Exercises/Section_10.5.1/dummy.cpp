#include <iostream>
#include <iterator>
#include <list>
#include <algorithm>

using namespace std;

int main(void) {
    list<int> lint  {5,3,2,4,1,9};
    ostream_iterator<int> writeInt(cout, " ");

    cout << "Reverse the lint: " << endl;
    reverse(lint.begin(), lint.end());
    // display the lint
    cout << "After reverse lint: " << endl;
    copy(lint.cbegin(), lint.cend(), writeInt);
    cout << endl;

    return 0;
}