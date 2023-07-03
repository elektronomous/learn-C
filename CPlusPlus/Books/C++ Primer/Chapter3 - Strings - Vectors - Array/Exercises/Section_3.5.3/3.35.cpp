#include <iostream>
#include <iterator>

using std::cout,
      std::cin,
      std::endl,
      std::begin,
      std::end;

int main(void) {
    int arr[] = {1,2,3,4,5,6,7};

    // first look at the current contents of arr
    cout << "Current arr contents: " << endl;
    for (int &v : arr) 
        cout << v << " ";
    cout << endl;

    // now replace all the contents to zero using pointer
    for (int *pbeg = begin(arr); pbeg != end(arr); pbeg++)
        *pbeg = 0;
    
    // show the result
    cout << "After replace with zero: " << endl;
    for (int *pbeg = begin(arr); pbeg != end(arr); pbeg++)
        cout << *pbeg << " ";
    cout << endl;


}