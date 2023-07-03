#include <iostream>
#include <vector>

using std::cin,
      std::cout,
      std::endl,
      std::vector;

int main(void) {
    vector<int> vint1 = {0,2,1,5,2,11,9,0},
                vint2 = {1,2,5,2,3,5,3},
                vint3 = {0,2,1,5};

    unsigned truecounter = 0;

    for (decltype(vint1.size()) index = 0, sz = vint1.size();
         (index < sz) && (vint2[index] == vint1[index]); truecounter++, index++)
            ;
    
    if (truecounter == vint2.size())
        cout << "The vint1 is prefixed by vint2" << endl;
    else
        cout << "The vint1 isn't prefixed by vint2" << endl;
    
    truecounter = 0;

    for (decltype(vint1.size()) index = 0, sz = vint1.size();
        (index < sz) && (vint3[index] == vint1[index]); truecounter++, index++)
            ;

    if (truecounter == vint3.size())
        cout << "The vint1 is prefixed by vint3" << endl;
    else
        cout << "The vint1 isn't prefixed by vint3" << endl;
    
    return 0;
}