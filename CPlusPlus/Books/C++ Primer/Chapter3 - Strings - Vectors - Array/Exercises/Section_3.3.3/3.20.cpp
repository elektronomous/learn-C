#include <iostream>
#include <vector>
#include <string>

using std::cin,
      std::vector, 
      std::string,
      std::cout,
      std::endl;

using vint = vector<int>;
using vstr = vector<string>;

int main(void) {
    int input;
    vint v;

    // prompt user
    cout << "Enter numbers seperated by space: " << endl;
    while(cin >> input)
        v.push_back(input);
    
    // get the size of the vector first
    vint::size_type vsz = v.size();

    // result when sum the adjacent element
    cout << "Result in adjacent element: " << endl;
    for (vint::size_type i = 0; i < vsz; i++)
        if (i + 1 < vsz)
            cout << v[i] + v[i+1] << " ";
    cout << endl;
    
    // result when sum the first - last, the second, the second last, ... so on
    cout << "Result in first last order: " << endl;

    for (vint::size_type i = 0; i < vsz/2; i++)
        cout << v[i] + v[--vsz] << " ";
    cout << endl;
    
    return 0;
}