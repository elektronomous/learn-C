#include <iostream>

using namespace std;

int main(void) {
    int i,
        *pil = &i,
        *pi2 = nullptr;
    
    double *pd = new double(33),
           *pd2 = pd;
    
    delete i;       // error: i is not a pointer
    delete pil;     // undefined: pil refers to a local
    delete pd;      // ok
    delete pd2;     // undefined: the memory pointed to by pd2 was already freed
    delete pi2;     // ok: it is always ok to delete a null pointer

    /*  Although the value of a const object cannot be modified, the object itself can be
        destroyed. As with any other dynamic object, a const dynamic object is freed by
        executing delete on a pointer that points to that object
    */
   const int *pci = new const int (1024);
   delete pci;  // ok: deletes a const object
}