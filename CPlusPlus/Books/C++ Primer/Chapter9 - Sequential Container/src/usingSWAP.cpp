#include <vector>
#include <list>
#include <iostream>

using namespace std;

int main(void) {
    vector<int> vint{1,2,3,4,5};
    vector<int> lint{4,3,2};

    string str1 = "Hello There",
           str2 = "Whatsup!";

    cout << "Before swap two container element: " << endl;
    cout << "vint: ";
    for (const int &val: vint)
        cout << val << " ";
    cout << endl;

    cout << "lint: ";
    for (const int &val: lint)
        cout << val << " ";
    cout << endl;

    swap(vint, lint);
    cout << "vint: ";
    for (const int &val: vint)
        cout << val << " ";
    cout << endl;

    cout << "lint: ";
    for (const int &val: lint)
        cout << val << " ";
    cout << endl;

    // string
    cout << "Before swap two string: " << endl;
    cout << "str1: " << str1 << endl;
    cout << "str2: " << str2 << endl;
    str1.swap(str2);
    cout << "str1: " << str1 << endl;
    cout << "str2: " << str2 << endl;

    // string swap invalidate the iterators, references and pointers
    string::iterator toStr1 = str1.begin();
    cout << "str1 first element before swap: " << *toStr1 << endl;  // => W
    // call swap on str1
    str1.swap(str2);
    cout << "str1 first element after swap: " << *toStr1 << endl;   // => H

    // call swap on the seq container except string will validate iterator, references and pointers
    vector<int>::iterator toVint = vint.begin();
    cout << "toVint before swap: " << *toVint << endl;  /* 4 */
    // call swap on iterator
    vint.swap(lint);
    cout << "toVint after swap: " << *toVint << endl;   /* it stays 4 right here */
    
    /* invalidate means that the iterators, references, and pointers are still remain 
       point to the same container's element.
       
       validate menas that the iterators, references, and pointers are swapped too. so they're
       still point to the element but on the different container. 
    */


    return 0;
}