#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
    int sz;

    auto f =  [sz] (int i) { return i + sz; };
    /* 
        Iam using auto here because i don't know yet the suitable conversion
        from that lambda.
    */

    return 0;
}