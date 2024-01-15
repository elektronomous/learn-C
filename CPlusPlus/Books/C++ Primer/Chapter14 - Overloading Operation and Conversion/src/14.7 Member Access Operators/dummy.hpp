#include <iostream>
#include "StrBlob.hpp"

int main(void) {
    StrBlob a1 = {"hi", "bye", "now"};  
    StrBlobPtr p(a1);           // p points to the vector inside a1

    *p = "okay";                    // assigns to the first element in a1
    cout << p->size() << endl;      // prints 4, the size of the ifrst element in a1
    cout << (*p).size() << endl;    // equivalent to p->size()

    return 0;
}