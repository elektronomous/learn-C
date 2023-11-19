#include <iostream>
#include "StrBlob.hpp"

using namespace std;

int main(void) {
    StrBlob b1;
    {
        StrBlob b2 = {"a","an","the"};
        b1 = b2;                        // This will increment the reference count
                                        // of shared_ptr inside the b2
        b2.push_back("about");          // increment the vector inside the b2 and b1
    }

    cout << "The size of b1: " << b1.size() << endl;    // the elements => 4

    return 0;
}