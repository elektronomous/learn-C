#include <iostream>
#include <string>

using namespace std;

class HasPtr {
    public:
        // constructor allocates new string and a new counter, which it sets to 1
        HasPtr(const string &s = string()):
            ps(new string()), i(0), count(new size_t(1)) {}
        
        // copy constructor copies all three data members and increments the counter
        HasPtr(const HasPtr &rhs):
            ps(rhs.ps), i(rhs.i), count(rhs.count) {
                *count++;
            }
        HasPtr& operator=(const HasPtr &rhs);
        ~HasPtr();
        
    private:
        string *ps;
        int i;
        size_t *count;
};

HasPtr::~HasPtr() {
    if (--*count == 0) {    // if the reference count goes to 0
        delete ps;          // delete the string
        delete count;       // and the counter 
    }
}

HasPtr& HasPtr::operator=(const HasPtr &rhs) {
    ++*rhs.count;               // increment the use count of the right-hand operand
    if (--*count == 0) {        // then decrement this object's counter
        delete ps;              // if no other users
        delete count;           // free this object's allocated members
    }
    ps = rhs.ps;                // copy data from rhs into this object
    i = rhs.i;
    count = rhs.count;

    return *this;
}