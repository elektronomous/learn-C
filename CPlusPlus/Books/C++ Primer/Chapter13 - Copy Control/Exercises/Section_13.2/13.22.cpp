#include <iostream>
#include <string>

using namespace std;

class HasPtr {
    public:
        HasPtr(const std::string &s = std::string()):
            ps(new std::string(s)), i(0) { }
        
        // copy-control operations
        HasPtr(const HasPtr &h);
        HasPtr& operator=(const HasPtr &h);
        ~HasPtr();

        HasPtr& operator=(const HasPtr &rhs);
    private:
        std::string *ps;
        int i;
};

HasPtr::HasPtr(const HasPtr &h):
    ps(new string(*h.ps)), i(h.i) {}

HasPtr& HasPtr::operator=(const HasPtr &h) {
    string *newMem = new string(*h.ps);
    delete ps;
    ps = newMem;
    i = h.i;

    return *this;
}

HasPtr::~HasPtr() {
    delete ps;
}