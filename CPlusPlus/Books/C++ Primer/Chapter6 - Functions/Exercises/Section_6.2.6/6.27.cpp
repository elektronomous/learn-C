#include <iostream>
#include <initializer_list>

using namespace std;

int sumList(const initializer_list<int> &il) {
    int result = 0;
    
    for (const int &val: il)
        result += val;
    
    return result;
}

int main(void) {
    int resultSum = sumList({1,2,3,4,5});

    cout << "The result from sumList: " << resultSum << "\n";

    return 0;
}