#include <iostream>
#include <deque>

using namespace std;

int main(void) {
    deque<double> deqDouble {1.5, 2.5, 3.5};
    deque<double>::iterator middleElement = deqDouble.begin() + 1;
    deque<double>::reference toMiddle = deqDouble.at(1);

    cout << "The address of each element before push_back: " << endl;
    for (const double &d: deqDouble)
        cout << &d << " | " << d << endl;
    
    cout << "The address of iterator middleElement: " << &(*middleElement) << endl;
    cout << "The address of reference toMiddle: " << &toMiddle << endl; 
    
    deqDouble.push_back(4.5);
    deqDouble.push_front(5.5);

    cout << "The address of each elemente after push_back: " << endl;
    for (const double &d: deqDouble)
        cout << &d << " | " << d << endl;
    
    cout << "The address of iterator middleElement: " << *middleElement << endl;
    cout << "The address of reference toMiddle: " << &toMiddle << endl;

    return 0;
}
/*
elektronomous@elektronomouss-MacBook-Pro VALIDATE_INVALIDATE_ITERATORS % ./2.1
    The address of each element before push_back: 
    0x7fd603008800 | 1.5
    0x7fd603008808 | 2.5
    0x7fd603008810 | 3.5
    The address of iterator middleElement: 0x7fd603008808
    The address of reference toMiddle: 0x7fd603008808
elektronomous@elektronomouss-MacBook-Pro VALIDATE_INVALIDATE_ITERATORS % ./2.1
    The address of each element before push_back: 
    0x7f96e0808800 | 1.5
    0x7f96e0808808 | 2.5
    0x7f96e0808810 | 3.5
    The address of iterator middleElement: 0x7f96e0808808
    The address of reference toMiddle: 0x7f96e0808808
    The address of each elemente after push_back: 
    0x7f96e0808800 | 1.5
    0x7f96e0808808 | 2.5
    0x7f96e0808810 | 3.5
    0x7f96e0808818 | 4.5
    The address of iterator middleElement: 0x7f96e0808808
    The address of reference toMiddle: 0x7f96e0808808
elektronomous@elektronomouss-MacBook-Pro VALIDATE_INVALIDATE_ITERATORS % ./2.1
    The address of each element before push_back: 
    0x7fb860008800 | 1.5
    0x7fb860008808 | 2.5
    0x7fb860008810 | 3.5
    The address of iterator middleElement: 0x7fb860008808
    The address of reference toMiddle: 0x7fb860008808
    The address of each elemente after push_back: 
    0x7fb860008800 | 1.5
    0x7fb860008808 | 2.5
    0x7fb860008810 | 3.5
    0x7fb860008818 | 4.5
    0x7fb860008820 | 5.5
    The address of iterator middleElement: 0x7fb860008808
    The address of reference toMiddle: 0x7fb860008808
elektronomous@elektronomouss-MacBook-Pro VALIDATE_INVALIDATE_ITERATORS % ./2.1
    The address of each element before push_back: 
    0x7ff20d808800 | 1.5
    0x7ff20d808808 | 2.5
    0x7ff20d808810 | 3.5
    The address of iterator middleElement: 0x7ff20d808808
    The address of reference toMiddle: 0x7ff20d808808
    The address of each elemente after push_back: 
    0x7ff20d808800 | 1.5
    0x7ff20d808808 | 2.5
    0x7ff20d808810 | 3.5
    0x7ff20d808818 | 4.5
    0x7ff20d808820 | 5.5
    The address of iterator middleElement: 2.5
    The address of reference toMiddle: 0x7ff20d808808
elektronomous@elektronomouss-MacBook-Pro VALIDATE_INVALIDATE_ITERATORS % ./2.1
    The address of each element before push_back: 
    0x7faa1f808800 | 1.5
    0x7faa1f808808 | 2.5
    0x7faa1f808810 | 3.5
    The address of iterator middleElement: 0x7faa1f808808
    The address of reference toMiddle: 0x7faa1f808808
    The address of each elemente after push_back: 
    0x7faa1f80b7f8 | 5.5
    0x7faa1f808800 | 1.5
    0x7faa1f808808 | 2.5
    0x7faa1f808810 | 3.5
    0x7faa1f808818 | 4.5
    The address of iterator middleElement: 2.5
    The address of reference toMiddle: 0x7faa1f808808
*/