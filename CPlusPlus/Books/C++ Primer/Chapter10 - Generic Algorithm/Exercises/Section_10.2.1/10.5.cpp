#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    vector<const char *> roaster1 {"faza","zulfi","alfred"},
                         roaster2 {"faza","zulfi","alfred"},
                         roaster3 {"wido","indra","rudi"};

    if (equal(roaster1.cbegin(), roaster1.cend(), roaster2.cbegin()))
        cout << "roaster1 has the same contents with roaster2" << endl;
    
    if (equal(roaster1.cbegin(), roaster1.cend(), roaster3.cbegin()))
        cout << "roaster1 has the same contents with roaster3" << endl;
    else 
        cout << "roaster1 has different contents with roaster3" << endl;

    return 0;
}