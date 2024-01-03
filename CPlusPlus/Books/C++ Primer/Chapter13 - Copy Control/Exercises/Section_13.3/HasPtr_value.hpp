#include <iostream>
#include <string>

using namespace std;

class HasPtr {
    // swap function
    friend void swap(HasPtr&, HasPtr&);    
    public:
        HasPtr(const std::string &s = std::string()):
            ps(new std::string(s)), i(0) { }
        
        // copy-control operations
        HasPtr(const HasPtr &h);
        HasPtr& operator=(const HasPtr &h);
        ~HasPtr();

        // 13.31.cpp
        bool operator<(const HasPtr &h) { return (*ps < *h.ps); }

        string getString() { return *ps; }
    private:
        std::string *ps;
        int i;
};

HasPtr::HasPtr(const HasPtr &h):
    ps(new string(*h.ps)), i(h.i) {}

HasPtr& HasPtr::operator=(const HasPtr &h) {
    string *newMem = new string(*h.ps);     // copy the underlying string
    delete ps;                              // free the old memory
    ps = newMem;                            // copy data from h
    i = h.i;                        

    return *this;
}
/*

in this assignment operator, we quite clearly first do the work of the constructor:
The initializer of newMem is identical to the initializer of ps in HasPtr’s copy constructor.
As in the destructor, we next delete the string to which ps currently points. 
What remains is to copy the pointer to the newly allocated string and the int value from 
h into this object.

*/

HasPtr::~HasPtr() {
    delete ps;
}

void swap(HasPtr &lhs, HasPtr &rhs) {
    using std::swap;
    swap(lhs.ps, rhs.ps);
    swap(lhs.i, rhs.i);
}