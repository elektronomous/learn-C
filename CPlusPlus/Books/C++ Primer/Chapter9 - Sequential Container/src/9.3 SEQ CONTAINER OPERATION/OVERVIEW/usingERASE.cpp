#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    vector<int> vint {1,2,3,4,5,6,7,8,9};

    vector<int>::iterator firstIterator = vint.begin();

    // erase first element denoted by iterator
    vector<int>::iterator secondIterator = vint.erase(firstIterator);                    // return the iterator the following element

    // erase the from 1 - 4 elements
    firstIterator = vint.begin();
    secondIterator = vint.begin() + 5;
    
    vector<int>::iterator equalToSecond = vint.erase(firstIterator, secondIterator);    // equalToSecond == secondIterator

    // display the values
    cout << "The equalToSecond value: " << *equalToSecond << endl;
    for (const int &val: vint)
        cout << val << " ";
    cout << endl;

    // clear the contents of the elements
    vint.clear();       // equal to vint.erase(vint.begin(), vint.end());
    
    return 0;
}