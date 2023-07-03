#include <iostream>
#include <vector>

using std::cout,
      std::cin,
      std::vector,
      std::begin,
      std::end,
      std::endl;


typedef vector<int> vint;

int main(void) {
    vint v {8, 7, 0, 9, 5, 2, 2, 1, 9, 3};

    cout << "Before odd value get doubled: ";
    for (const int &value: v)
        cout << value << " ";
    cout << endl;
    
    
    // double the odd value
    for (int &value: v)
        value = (value % 2) ? (value << 1) : value;

    cout << "After odd value get dobuled: ";
    for (const int &value: v)
        cout << value << " ";
    cout << endl;

    return 0;
}