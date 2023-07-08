#include <iostream>
#include <string>

using namespace std;

bool str_subrange(const string &str1, const string &str2) {
    
    // same sizes: return normal equality test
    if (str1.size() == str2.size())
        return str1 == str2;            // ok: == returns bool
    
    // find the size of the smaller string; conditional operator
    size_t size = (str1.size() < str2.size()) ? str1.size() : str2.size();

    // look at each element up to the size of the smaller string
    for (size_t i = 0; i < size; i++) {
        if (str1[i] != str2[i])
            return false;             // error #1: no return value; compiler should detect
                                // this error
    }
    return false;
    // error #2: control might flow off the end of the function without a return
    // the compiler might not detect this error
}

/* 
The result on error #1:
     error: return-statement with no value, in function returning ‘bool’ [-fpermissive

The result on error #2:
    error: control reaches end of non-void function [-Werror=return-type]
*/