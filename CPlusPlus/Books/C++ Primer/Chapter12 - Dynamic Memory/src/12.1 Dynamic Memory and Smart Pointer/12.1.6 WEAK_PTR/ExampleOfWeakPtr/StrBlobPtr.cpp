#include <iostream>
#include <memory>
#include <vector>
#include "StrBlobPtr.hpp"
#include "StrBlob.hpp"

using namespace std;

// StrBlobPtr throws an exception on attempts to access a nonexistent element
class StrBlobPtr {
    public:
        StrBlobPtr(): curr(0) { }   // implicit null to wptr
        StrBlobPtr(StrBlob &a, size_t sz = 0): 
            wptr(a.data), curr(sz) { }
        
        string& deref() const;
        StrBlobPtr& incr();     // prefix version
    
    private:
        // check returns a shared_ptr to the vector if the check succeeds
        shared_ptr<vector<string>> check(size_t, const string &) const;

        // store a weak_ptr which means underlying vector might be destroyed
        weak_ptr<vector<string>> wptr;  
        size_t curr;                    // current position within the array

};

shared_ptr<vector<string>> StrBlobPtr::check(size_t sz, const string &msg) const {
    shared_ptr<vector<string>> pointToVec = wptr.lock();

    if (!pointToVec)    // if null
        throw runtime_error("Unbound StrBlobPtr");

    if (sz >= pointToVec->size())   // if 
        throw out_of_range(msg);
    
    return pointToVec;          // otherwise return a shared_ptr to the vector
}

string& StrBlobPtr::deref() const {
    shared_ptr<vector<string>> getCurrVec = check(curr, "dereference past end");

    return (*getCurrVec)[curr];      // *p is the vector to which this object points
}

StrBlobPtr& StrBlobPtr::incr() {
    // if curr already points past the end of the continaer, can't increment it
    check(curr, "increment past end of StrBlobPtr");
    ++curr;     // advance the current state
    return *this;
}
