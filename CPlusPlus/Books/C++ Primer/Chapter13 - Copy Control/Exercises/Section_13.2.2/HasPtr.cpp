#include <iostream>
#include <memory>

using namespace std;

class HasPtr {
    // constructor allocates string
    HasPtr(const string &s = string()):
        ps(new string()), i(0) { }
    
    // copy initialized
    HasPtr(const HasPtr &rhs):
        ps(rhs.ps), i(rhs.i) { }
    
    // copy assignment
    HasPtr& operator=(const HasPtr &rhs);
    
    private:
        shared_ptr<string> ps;
        int i;
};

HasPtr& HasPtr::operator=(const HasPtr &rhs) {
    ps = rhs.ps;
    i = rhs.i;

    return *this;
}