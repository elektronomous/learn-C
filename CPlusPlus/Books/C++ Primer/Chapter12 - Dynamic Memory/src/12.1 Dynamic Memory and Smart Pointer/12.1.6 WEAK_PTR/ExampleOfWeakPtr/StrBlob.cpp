#include <iostream>
#include <memory>
#include <vector>
#include "StrBlob.hpp"
#include "StrBlobPtr.hpp"

using namespace std;

class StrBlob {
    // implicitly public
    friend class StrBlobPtr;
    StrBlobPtr begin();         // return the StrBlobPtr to the first element
    StrBlobPtr end();           // and one past the last element

    private:
        shared_ptr<vector<string>> data;
};

StrBlobPtr StrBlob::begin() {
    return StrBlobPtr(*this);   // return the new created object
}

StrBlobPtr StrBlob::end() {
    return StrBlobPtr(*this, data->size());
}