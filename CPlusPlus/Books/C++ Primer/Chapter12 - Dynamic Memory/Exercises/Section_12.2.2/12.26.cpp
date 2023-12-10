/*

    string *const p = new string[n];        // construct n empty string => this create the object of the string
    string s;
    string *q = p;                          // point to the first string

    while (cin >> s && q != p + n) 
        *q++ = s;                           // assign each of q with s
    const size_t size = q-p;                // remember how many string we read

    // use the array

    delete[] p;     // p points to an array; must remember to use delete[]
*/

#include <iostream>
#include <memory>
#include <string>

using namespace std;

int main(void) {
    allocator<string> allocStr;

    string *const p = allocStr.allocate(5);        // we allocate 5 memory area for string
    string *q = p;                                  // point to the first unconstructed memory
    string s;

    while (cin >> s && q != p + 5)
        allocStr.construct(q++, s);

    // show the result while destroy the element
    cout << "The result after you construct the string: " << endl;
    while (q != p) {
        cout << *q << endl;
        allocStr.destroy(--q);
    }

    // free the memory
    allocStr.deallocate(p, 5);

    return 0;

}