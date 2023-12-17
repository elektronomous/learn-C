#include <iostream>
#include <string>

using namespace std;

class HasPtr {
    public:
        HasPtr(const std::string &s = std::string()):
            ps(new std::string(s)), i(0) { }
        HasPtr(const HasPtr &h);
        HasPtr& operator=(const HasPtr &rhs);
    private:
        std::string *ps;
        int i;
};

HasPtr::HasPtr(const HasPtr &h):
    ps(h.ps), i(h.i)
 { }

HasPtr& HasPtr::operator=(const HasPtr &rhs) {
    ps = rhs.ps;
    i = rhs.i;
}