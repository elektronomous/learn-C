#include <iostream>
#include <memory>
#include <list>

using namespace std;

int main(void) {
    shared_ptr<string> p1;      // shared_ptr that can point at a string
    shared_ptr<list<int>> p2;   // shared_ptr that can point at a list of ints

    // if p1 is not null, check whether it's the empty string;
    if (p1 && p1->empty()) {
        *p1 = "Hy";             // if so, dereference p1 to assign a new value to that string
    }

    shared_ptr<int> p = make_shared<int>(42);   // object to which p points has one user   
    shared_ptr<int> q(p);                       // p and q point to the same object
                                                // object to which p and q point has two users

    shared_ptr<int> r = make_shared<int>(50);   // int to which r points has one user
    r = q;                                      /* assign to r, making it point to a different address
                                                 * increase the user count for the object to which q points
                                                 * reduce the use count of the object to which r had pointed
                                                 * the object r had pointed to has no users; that object is automatically
                                                   freed.
                                                 */
}