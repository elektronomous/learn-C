#include <iostream>
#include <memory>

using namespace std;

// a function that returns a shared_ptr cannot implicitly convert a plain pointer
// in its return statement
shared_ptr<int> clone(int p) {
    // return new int(p);       => error: implicit conversion to shared_ptr<int>
    return shared_ptr<int>(new int(p));
}

void process(shared_ptr<int> p) {
    cout << *p + 20 << endl;
}

int main(void) {
    shared_ptr<int> p2(new int(42));        // direct init: p2 points to an int with value 42
    /*
        The smart pointer constructors that take pointers are explicit
            shared_ptr<int> pi = new int(1024);     => error: must use direct initialization
    */

    process(p2);    // argument passed by value increment the p2 reference count

    int *x(new int(1024));          // dangerous: x is a plain pointer, not a smart pointer
    //  process(x)                  => error: can't convert plain to smart pointer
    process(shared_ptr<int>(x));    // legal: but the memory will be deleted
    int j = *x;                     // undefined: x is a dangling pointer

    /*
    In this call, we passed a temporary shared_ptr to process. That temporary is
    destroyed when the expression in which the call appears finishes. Destroying the
    temporary decrements the reference count, which goes to zero. The memory to which
    the temporary points is freed when the temporary is destroyed
    But x continues to point to that (freed) memory; x is now a dangling pointer.
    Attempting to use the value of x is undefined
    */
    {
        int *q = p2.get();  // get the address pointed by the smart pointer

        /* it is an error to bind another smart pointer to the pointer returned by get */
        // undefined: two independent shared_ptr point to the same memory
        shared_ptr<int>(q);
    } // block ends, q is destroyed, and the memory to which q points is freed
    int foo = *p2;  // the memory to which p2 points was freed

    /*
    Destroying q frees the memory to which q points. That makes p2 into a dangling pointer, 
    meaning that what happens when we attempt to use p2 is undefined. Moreover, when p2 is 
    destroyed, the pointer to that memory will be deleted a second time
    */
}

