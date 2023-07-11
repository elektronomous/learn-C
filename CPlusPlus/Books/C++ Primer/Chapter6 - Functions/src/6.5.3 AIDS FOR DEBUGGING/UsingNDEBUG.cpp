#include <iostream>

using namespace std;

int main(void) {

#ifndef NDEBUG
    cerr << "declare the debug, so this message is gone\n" << endl;
    return 1;
#endif

    cout << "Hello from " << __func__ << endl;

    return 0;
}

// Using NDEBUG: g++ -Wall -Werror -std=c++17 -D NDEBUG -o UsingNDEBUG UsingNDEBUG.cpp