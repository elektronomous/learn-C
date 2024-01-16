#include <iostream>

using namespace std;

struct AbsInt {
    int operator()(int val) const {
        return val < 0 ? -val : val;
    }
};

int main(void) {
    int i = -42;
    AbsInt absObj;      // object that has a function-call operator
    int ui = absObj(i); // passess i to absObj.operator()

    cout << "after call to absObj: " << ui << endl;

    return 0;
}