#include <iostream>
#include <vector>
#include "String.hpp"

using namespace std;

int main(void) {
    vector<String> vStr;

    for (int i = 0; i<6; i++)
        vStr.push_back(String("hello"));
    
    return 0;
}
/*
The result is only 5-times push_back:
1    Copy-constructor is called
2    Copy-constructor is called
3    Copy-constructor is called
4    Copy-constructor is called
5    Copy-constructor is called
6    Copy-constructor is called
7    Copy-constructor is called
8    Copy-constructor is called
9    Copy-constructor is called
10    Copy-constructor is called
11    Copy-constructor is called
12    Copy-constructor is called

Why? Let's us traceback:
    Remember push_back is a method and the way it works is that its parameter
    is using copy-constructor of the parameter's type. That's why you get 2
    copy-constructor printed in this way. first in the parameter type of the push_back
    method, and in the body of the method. The method is copy-initialized the vStr.

Why we get 12? Not 10? Iam sure that when the vector is reached out the 10, it reallocate
its element, and the elemetn that's exceed is the constructed memory that created by the vector
*/