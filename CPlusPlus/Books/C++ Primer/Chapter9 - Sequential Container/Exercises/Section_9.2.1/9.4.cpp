#include <iostream>
#include <vector>

using namespace std;

bool findInt(vector<int>::iterator start,
             vector<int>::iterator OffEnd,
             const int &val) {

    while (start != OffEnd) { 
        if (val == *start)
            return true;
        start++;
    }
    
    return false;
}

int main(void) {
    vector<int> vint {1,2,3,5,6,7,9,2,1,6,3,5,6,0};

    // find value 9
    if (findInt(vint.begin(), vint.end(), 9))
        cout << "The value 9 is found\n";
    else
        cout << "The value 9 isn't found\n";
    
    return 0;
}
