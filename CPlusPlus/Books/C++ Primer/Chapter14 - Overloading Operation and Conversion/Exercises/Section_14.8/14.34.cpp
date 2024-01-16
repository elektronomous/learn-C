#include <iostream>

using namespace std;

class IsOdd {
    public:
        IsOdd() = default;
        bool operator()(const int &tv, const int &TV, const int &FV) {
            return tv % 2 ? true : false;
        }
};

int main(void) {
    IsOdd testOdd;
    if (testOdd(5, true, false))
        cout << "odd" << endl;
    else
        cout << "even" << endl;
    return 0;    
}