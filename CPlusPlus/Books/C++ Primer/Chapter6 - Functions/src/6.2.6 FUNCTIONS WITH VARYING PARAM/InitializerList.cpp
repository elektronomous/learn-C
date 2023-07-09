#include <iostream>
#include <initializer_list>

using std::cin,
      std::cout,
      std::endl,
      std::initializer_list;

int main(void) {
    // the value on initializer_list always const
    // you can't change value within it.
    initializer_list<int> iList {1,2,3,4,5};
    initializer_list<int> iList2 (iList);       // share the same object 
                                                // or iList2 = iList

    cout << "Initializer int is size: " << iList.size() << endl;
    cout << "The second initializer_list is size: " << iList2.size() << endl;

    return 0;
}

/* 
The difference type that you get from for-loop and range-for while 
using initializer_list:

    const int *piList = iList.begin();

and
    
    for (const int &val: iList):
        ....
        ....
*/