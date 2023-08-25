#include <vector>
#include <iostream>

using namespace std;

int main(void) { 
    vector<int> vint {1,2};
    vector<int>::iterator vintBegin = vint.begin();

    // insert front on vector is expensive operation
    // it's like doing push_front but on the vector
    vint.insert(vintBegin, {7,8,9});        // insert {7,8,9} just before vintBegin


    for (const int &val: vint)
        cout << val << " ";
    cout << endl;


    vector<string> svec {"hello"};
    vector<string> v {"quasi", "simba", "frollow", "scar"};
    // insert into svec 2 "there" before "hello"
    vector<string>::iterator it = svec.insert(svec.begin(), 2, "there");
    if (it != svec.end())
        cout << "The value of iterator return by svec: " << *it << endl;
    // insert the last two elements of v at the beginning of svec
    svec.insert(svec.begin(), v.end()-2, v.end());
    // insert the initializer list before the ends of the svec
    svec.insert(svec.end(), {"hello", "there"});

    // run-time error: iterators denoting the range to copy from
    // must not refer to the same container as the one we are changing
    //      svec.insert(svec.begin(), svec.begin(), svec.end());
    // NOTE: if you try to print the it after insert it again, the iterator was
    //       invalidated. so you can't access the same element again. the container
    //       its element.

    for (const string &str: svec)
        cout << str << " ";
    cout << endl;


    return 0;
}