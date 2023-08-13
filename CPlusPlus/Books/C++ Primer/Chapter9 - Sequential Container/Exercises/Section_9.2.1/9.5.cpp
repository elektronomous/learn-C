#include <iostream>
#include <vector>

using namespace std;

vector<int>::iterator findInt(vector<int>::iterator start,
                              vector<int>::iterator OffEnd,
                              const int &val) {

    while (start != OffEnd) { 
        if (val == *start)
            return start;
        start++;
    }
    
    return OffEnd;
}

int main(void) {
    vector<int> vint {1,2,3,5,6,7,9,2,1,6,3,5,6,0};

    // find value 9
    if (findInt(vint.begin(), vint.end(), 9) != vint.end())
        cout << "The value 9 is found" << endl;
    else
        cout << "The value 9 isn't found" << endl;
    
    return 0;
}
