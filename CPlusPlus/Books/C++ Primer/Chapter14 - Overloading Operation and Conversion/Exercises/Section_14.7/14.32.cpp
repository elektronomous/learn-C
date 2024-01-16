#include <iostream>
#include "StrBlobPtrPtr.hpp"

using namespace std;

int main(void) {
    StrBlob listStr {"Hello", "World"};
    StrBlobPtr pListStr(listStr, 1);
    StrBlobPtrPtr ppListStr(&pListStr);

    cout << *pListStr << endl;
    cout << pListStr->size() << endl;
    cout << (*ppListStr)->size() << endl;
    cout << ppListStr->deref().size() << endl;
    cout << **ppListStr << endl;
    return 0;
}