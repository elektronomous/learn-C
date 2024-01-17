#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <algorithm>

using namespace std;

int main(void) {
    vector<string> vstr {"pooh", "pooh", "pooh"};
    not_equal_to<string> eqStr;

    vector<string>::iterator findStrThatIsNotPooh = find_if(vstr.begin(), vstr.end(), bind(eqStr, placeholders::_1, string("pooh")));
    
    if (findStrThatIsNotPooh == vstr.end())
        cout << "The pooh is found everywhere in the vstr" << endl;
    else
        cout << "The first string that's found not equal to \"pooh\": " << *findStrThatIsNotPooh << endl;


    return 0;
}