#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;

typedef vector<int> vint;
typedef vector<string> vstr;

int main(void) {
    int input;
    vint vi;

    // prompt user 
    cout << "Enter numbers seperated by space: " << endl;
    while(cin >> input)
        vi.push_back(input);

    // result when sum the adjacent element
    cout << "Return in adjacent element: " << endl;
    for (vint::const_iterator it = vi.cbegin(); it != vi.cend(); it++)
        if ((it + 1) != vi.cend())
            cout << *it + *(it + 1) << " ";
    cout << endl;

    // result when sum the first - last, the second - the second last... order.
    // get the middle iterator of the element

    vint::iterator end = vi.end()-1;
    cout << "Return in first last order: " << endl;
    for (vint::iterator beg = vi.begin(); beg < end; beg++) {
        cout << *beg + *end << " ";
        end--;
    }
    cout << endl;

    return 0;
}