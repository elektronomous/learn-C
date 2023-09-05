#include <iostream>
#include <list>

using namespace std;

int main(void) {
    list<int> lint {0,1,2,3,4,5,6};
    list<int>::iterator begin_lint = lint.begin();

    while (begin_lint != lint.end()) {
        if (*begin_lint % 2) {
            begin_lint = lint.insert(begin_lint, *begin_lint);
            for (int n = 0; n < 2; n++)
                begin_lint++;
        } else 
            begin_lint = lint.erase(begin_lint);
    }

    // display the result
    cout << "The content of lint: ";
    for (const int &val: lint)
        cout << val << " ";
    cout << endl;

    return 0;
}