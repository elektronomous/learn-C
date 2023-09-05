#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    vector<int> vint;

    cout << "Vector's size: " << vint.size()
         << ", capacity: " << vint.capacity() << endl;
    
    cout << "push_back values.." << endl;

    for (vector<int>::size_type x = 0; x < 24; x++)
        vint.push_back(x);
    
    cout << "Vector's size: " << vint.size()
         << ", capacity: " << vint.capacity() << endl;
    
    cout << "resize the container to 15 elements.." << endl;
    vint.resize(15);

    cout << "Vector's size: " << vint.size()
         << ", capacity: " << vint.capacity() << endl;
    
    cout << "reserve for the bigger capacity.." << endl;
    vint.reserve(50);

    cout << "Vector's size: " << vint.size()
         << ", capacity: " << vint.capacity() << endl;

    cout << "shrink to fit, make the capacity = size.." << endl;
    vint.shrink_to_fit();

    cout << "Vector's size: " << vint.size()
         << ", capacity: " << vint.capacity() << endl;
    
    return 0;
}

/*  
Vector's size: 0, capacity: 0
push_back values..
Vector's size: 24, capacity: 32

resize the container to 15 elements
Vector's size: 15, capacity: 32

reserve for the bigger capacity..
Vector's size: 15, capacity: 50

shrink to fit, make the capacity = size..
Vector's size: 15, capacity: 15
*/