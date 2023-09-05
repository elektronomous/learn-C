#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(void) {
    vector<string> vstr;
    string word = "Hello";

    // insert 256 string
    for (vector<string>::size_type n = 0; n < 256; n++)
        vstr.push_back(word);
    cout << "Capacity before resize: " << vstr.capacity() << endl;
    // then grow the vector as much as the half of its initialized elements
    vstr.resize(vstr.size() + vstr.size()/2);

    cout << "After inserting 256 words and grow the vector as much\n"
         << "as the half of its initialized elements" << endl;
    cout << "its capacity: " << vstr.capacity() << endl;

    cout << endl;

    // what if 512
    for (vector<string>::size_type n = 0; n < 512; n++)
        vstr.push_back(word);
    cout << "Capacity before resize: " << vstr.capacity() << endl;
    // then grow the vector as much as the half of its initialized elements
    vstr.resize(vstr.size() + vstr.size()/2);
    cout << "After inserting 512 words and grow the vector as much\n"
         << "as the half of its initialized elements" << endl;
    cout << "its capacity: " << vstr.capacity() << endl;

    return 0;
}

/*
Capacity before resize: 256
After inserting 256 words and grow the vector as much
as the half of its initialized elements
its capacity: 512

Capacity before resize: 1024
After inserting 512 words and grow the vector as much
as the half of its initialized elements
its capacity: 2048

= From this we conclude that the capacity is changed when 
  we request to resize greater than the current size.

*/