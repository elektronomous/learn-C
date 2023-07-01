#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

typedef vector<int> vint;

int main(void) {
    vint vi(10, 5);

    for (vint::iterator it = vi.begin(); it != vi.end(); it++)
        *it *= 2;
    
    // show result
    for (int &val : vi) 
        cout << val << " ";
    cout << endl;

    return 0;
}