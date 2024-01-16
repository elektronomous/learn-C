#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class IsEqual { 
    public:
        IsEqual(const int &val):
            cmpVal(val) { }

        bool operator()(const int &val) {
            return ( cmpVal == val );
        }
    
    private:
        int cmpVal;
};

int main(void) {
    vector<int> vint {1,2,3,4,5,5,7,9,9,11,5};

    cout << "Vector of ints before replace: " << endl;
    for_each(vint.cbegin(), vint.cend(), [](const int &i) { cout << i << " "; });
    cout << endl;

    replace_if(vint.begin(), vint.end(), IsEqual(5), 0);

    cout << "Vector of ints after replace: " << endl;
    for_each(vint.cbegin(), vint.cend(), [](const int &i) { cout << i << " "; });
    cout << endl;
    
    return 0;   
}