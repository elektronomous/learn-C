#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    vector<int> vint;

    for (vector<int>::size_type n = 0; n<10; n++) {
        vint.push_back(n);
        cout << "Vector's size: " << vint.size() << endl;
        cout << "Vector's capacity: " << vint.capacity() << endl;
    }

    return 0;
}
/* 
Vector's size: 1
Vector's capacity: 1
Vector's size: 2
Vector's capacity: 2
Vector's size: 3
Vector's capacity: 4
Vector's size: 4
Vector's capacity: 4
Vector's size: 5
Vector's capacity: 8
Vector's size: 6
Vector's capacity: 8
Vector's size: 7
Vector's capacity: 8
Vector's size: 8
Vector's capacity: 8
Vector's size: 9
Vector's capacity: 16
Vector's size: 10
Vector's capacity: 16

= From which you can see, the vector is double its capacity
  on each adding operation.
*/