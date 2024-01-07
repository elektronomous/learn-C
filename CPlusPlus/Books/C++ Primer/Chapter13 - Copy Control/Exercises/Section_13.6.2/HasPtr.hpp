#include <iostream>
#include <string>

using namespace std;

class HasPtr {
    friend void swap(HasPtr&,HasPtr&);
    public:
        HasPtr(const std::string &s = std::string()):
            ps(new std::string(s)), i(0) { }
        
        // copy-control operations
        HasPtr(const HasPtr &h);
        HasPtr& operator=(const HasPtr &h);
        ~HasPtr();

        // 13.6.2
        HasPtr(HasPtr&& p) noexcept: ps(p.ps), i(p.i) { p.ps = nullptr; }

        // 13.49.txt
        HasPtr& operator=(HasPtr&&) noexcept;

        // 13.6.2 assignment operator is both the move-and copy-assignment operator
        HasPtr& operator=(HasPtr rhs) {
            cout << "Copy-and-swap assignment operator is called" << endl;
            using std::swap;
            swap(*this, rhs);
            return *this;
        }

        // HasPtr& operator=(const HasPtr &rhs);
    private:
        std::string *ps;
        int i;
};

HasPtr::HasPtr(const HasPtr &h):
    ps(new string(*h.ps)), i(h.i) {}

/*
HasPtr& HasPtr::operator=(const HasPtr &h) {
    string *newMem = new string(*h.ps);     // copy the underlying string
    delete ps;                              // free the old memory
    ps = newMem;                            // copy data from h
    i = h.i;                        

    return *this;
}
*/

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

// 13.49.txt
HasPtr& HasPtr::operator=(HasPtr &&rhs) noexcept { 
    cout << "Move-assignment operator is called" << endl;
    if (this != &rhs) {
        delete ps;
        ps = rhs.ps;
        i = rhs.i;
        // make the rhs to be safely destructible
        rhs.ps = nullptr;
        rhs.i = 0;
    }

    return *this;
}