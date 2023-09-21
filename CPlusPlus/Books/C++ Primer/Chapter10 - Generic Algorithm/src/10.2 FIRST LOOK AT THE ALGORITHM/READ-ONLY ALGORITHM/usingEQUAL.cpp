#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(void) {
    /* lets us determine whether two sequences hold the same values */
    vector<string> roaster1 {"faza","zulfi","alfred"},
                   roaster2 {"faza","zulfi","alfred"},
                   roaster3 {"wido","indra","joko"};

    if (equal(roaster1.cbegin(), roaster1.cend(), roaster2.cbegin()))
        cout << "The roaster1 and roaster2 has same contents" << endl;
    
    if (equal(roaster1.cbegin(), roaster1.cend(), roaster3.cbegin()))
        cout << "The roaster1 and roaster3 has the same contents" << endl;
    else
        cout << "The roaster1 and roaster3 has different contents" << endl;
    
    return 0;
}