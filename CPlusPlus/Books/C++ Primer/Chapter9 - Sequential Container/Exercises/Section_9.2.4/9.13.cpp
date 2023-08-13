#include <iostream>
#include <vector>
#include <list>

using namespace std;

int main(void) {
    list<int> lint {1,2,3,4,5};
    vector<int> vint {1,2,3,4,5};

    /* How would you initialize a vector<double> from a list<int>?
       from a vector<int>?
    */
   vector<double> vdouble(vint.begin(), vint.end());
   vector<double> vdouble2(lint.begin(), lint.end());

   return 0;
}