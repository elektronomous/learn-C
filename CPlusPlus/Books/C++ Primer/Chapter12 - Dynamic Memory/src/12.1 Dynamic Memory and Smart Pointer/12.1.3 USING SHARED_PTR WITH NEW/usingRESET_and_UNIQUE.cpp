#include <iostream>
#include <memory>

using namespace std;

int main(void) {
    shared_ptr<int> pInt(new int(10));      // => point to an int that has value 10

    if (!pInt.unique())     // if we're not alone point to this address
        pInt.reset(new int(20));   // change this pointer to point to an int that has value 20

    /*
    Reset updates the reference counts and, if appropriate, deletes
    the object to which p points. The reset member is often used together with
    unique to control changes to the object shared among several shared_ptrs.
    */
    return 0;
}