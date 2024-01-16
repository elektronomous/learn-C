#include <iostream>
#include "StrBlobPtrPtr.hpp"

using namespace std;

int main(void) {
    StrBlob listStr {"Hello", "World"};
    StrBlobPtr pListStr(listStr, 1);
    StrBlobPtrPtr ppListStr(pListStr);

    cout << *pListStr << endl;
    cout << pListStr->size() << endl;
    cout << ppListStr->size() << endl;
    return 0;
}