#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    /* the problem here literal value is implemented-defined that's why the address is the same */
    vector<const char *> roaster1 {"faza","zulfi","alfred"},
                         roaster2 {"faza","zulfi","alfred"},
                         roaster3 {"wido","indra","rudi"};

    /* how const char * get == operator works ? */
    cout << "The address of each element on roaster1" << endl;
    for (const char *str: roaster1) {
        const int *p = reinterpret_cast<const int*>(&str);
        cout << "The address of string \"" << str << "\":\t" << p << endl;
    }
    cout << endl;

    /* how const char * get == operator works ? */
    cout << "The address of each element on roaster2" << endl;
    for (const char *str: roaster2) {
        int *p = reinterpret_cast<int*>(&str);
        cout << "The address of string \"" << str << "\":\t" << p << endl;
    }
    cout << endl;

    /* how const char * get == operator works ? */
    cout << "The address of each element on roaster3" << endl;
    for (const char *str: roaster3) {
        int *p = reinterpret_cast<int*>(&str);
        cout << "The address of string \"" << str << "\":\t" << p << endl;
    }
    cout << endl;

    if (equal(roaster1.cbegin(), roaster1.cend(), roaster2.cbegin()))
        cout << "roaster1 has the same contents with roaster2" << endl;
    
    if (equal(roaster1.cbegin(), roaster1.cend(), roaster3.cbegin()))
        cout << "roaster1 has the same contents with roaster3" << endl;
    else 
        cout << "roaster1 has different contents with roaster3" << endl;

    return 0;
}