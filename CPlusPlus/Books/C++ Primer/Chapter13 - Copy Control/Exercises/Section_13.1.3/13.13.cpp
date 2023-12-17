#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct X {
    X() { std::cout << "X()" << std::endl; }
    X(const X&) { std::cout << "X(const X&)" << endl; }
    
    // copy-assignment operator
    X& operator=(const X& x) { std::cout << "operator=(const X&)" << std::endl; return *this; }
    // destructor
    ~X() { std::cout << "~X()" << std::endl; }
};

void f1(struct X x) { cout << "f1 is called" << endl; }
void f2(struct X& x) { cout << "f2 is called" << endl; }

int main(void) {
    struct X x, anotherX(x);
    struct X y;
    y = x;
    vector<struct X> vXs;

    f1(x);
    f2(x);
}