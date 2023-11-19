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

shared_ptr<Foo> factory(int n) {
    // shared_ptr will take care of deleting this memory
    return make_shared<Foo>(n);
}

/* because factory returns a shared_ptr, we can be sure that object allocated
   by factory will be freed when appropriate.
*/

void use_factory(int n) {
    shared_ptr<Foo> p = factory(n);
    // use p
}   // p goes out of scope: the memory to which p points is automatically freed

/* in this case, p is the only object referring to the memory returned by factory.
   Because p is about to go away, the object to which p points will be destroyed and
   the memory in which that object resides will be freed.
*/

shared_ptr<Foo> anotherUse_factory(int n) {
    shared_ptr<Foo> p = factory(n);
    // use p

    return p;       // reference count is incremented when we return p
}   // p goes out of scope; the memory to which p points is not freed

/* in this version, the return statement in anotherUse_factory returns a copy of p
   to its caller. Copying a shared_ptr adds to the reference count of that object.
   Now when p is destroyed, there will be another user for the memory to which p points.
   The shared_ptr class ensures that so long as there are any shared_ptrS attached to that
   memory, the memory itself will not be free
*/