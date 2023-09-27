#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

/*
A call to sort arranges the elements in the input range into sorted order using the element type’s <
operator.
*/

int main(void) {
    vector<string> stories {"the","quick","red","fox","jumps", "over","the","slow","red","turtle"};

    cout << "Before sort: " << endl;
    for (const string &str: stories)
        cout << str << " ";
    cout << endl;

    cout << "After sort: " << endl;
    sort(stories.begin(), stories.end());

    for (const string &str: stories)
        cout << str << " ";
    cout << endl;

    return 0;
}