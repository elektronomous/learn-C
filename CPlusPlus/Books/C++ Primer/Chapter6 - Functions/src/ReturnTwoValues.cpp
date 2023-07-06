#include <iostream>
#include <string>

using std::cin,
      std::cout,
      std::endl,
      std::string;

// returns the index of the first occurance of c in s
// the reference parameters occurs counts how of c occurs
string::size_type find_char(const string &s, char c, string::size_type &occurs) {
    size_t ret = s.size();      // position of the first occurence, if any
    occurs = 0;                 // set the occurance count parameter

    for (size_t i = 0; i < s.size(); i++) {
        if (s[i] == c) {
            if (ret == s.size())
                ret = i;        // remember the first occurance of c
            ++occurs;           // increment the occurance count
        }
    }

    return ret;                 // count is returned implicitly in occurs
}

/* 
If you noticed that ret is only use to outsmart algorithm
where you can set it only once in another value.
what a brains!!

*/