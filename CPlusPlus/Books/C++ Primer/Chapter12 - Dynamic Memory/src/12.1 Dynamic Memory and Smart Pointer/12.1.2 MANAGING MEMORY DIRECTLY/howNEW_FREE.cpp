#include <iostream>
#include <memory>

using namespace std;

class Foo {
    private:
        size_t number;
    public:
        Foo() = default;
        Foo(size_t x): number(x) { }
        
};

Foo* factory(int arg) {
    // process arg as appropriate
    return new Foo(arg);        // caller is responsible for deleting this memory
}

// we forget to free the memory
void use_factory(int arg) {
    Foo *p = factory(arg);
    // use p but not delete it
}   // p goes out of scope, but the memory to which p points is not freed!

// we should fix the bug using the safest version of use_factory
void safe_use_factory(int arg) {
    Foo *p = factory(arg);
    delete p;               // remember to free the memory now that we no longer need it
    /* */
}

int main(void) {
    int *p(new int(42));        // p points to dynamic memory
    int *q = p;                 // p and q point to the same memory
    delete p;                   // invalidate both p and q
    p = nullptr;                // indicates that p has no longer bound to an object
}