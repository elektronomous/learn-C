#include <iostream>

using namespace std;

int main(void) {
    int val = 10;
    int *pVal = &val;

    char *pc = reinterpret_cast<char*>(pVal);

    cout << pc << endl;

    return 0;
}