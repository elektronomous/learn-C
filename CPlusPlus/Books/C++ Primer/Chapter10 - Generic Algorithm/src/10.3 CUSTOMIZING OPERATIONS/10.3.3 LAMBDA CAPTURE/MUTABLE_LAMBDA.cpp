#include <iostream>

using namespace std;

int main(void) {
    size_t sz = 42;     // local variable
    // f can change the value it captures
    auto f = [sz] () mutable { return ++sz; };

    /* you cant change value that is copy by value inside lambda 
       that's why the mutable is needed
    */
    sz = 0;
    cout << f() << endl;    // 43
    cout << f() << endl;    // 44

    return 0;

}