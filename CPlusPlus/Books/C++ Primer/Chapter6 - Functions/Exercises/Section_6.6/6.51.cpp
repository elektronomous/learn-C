#include <iostream>

using namespace std;

void f();
void f(int);
void f(int, int);
void f(double, double = 3.14);

inline void f(void) {
    cout << "This is from f(void)" << endl;
}

inline void f(int i) {
    cout << "This is from f(int)" << endl;
}

inline void f(int i, int j) {
    cout << "This is from f(int ,int)\n";
}

inline void f(double j, double i) {
    cout << "This is from f(double, double)\n";
}

int main(void) {
    //  f(2.56, 42);        => more than one instance of overloaded function "f" matches the argument list:
    // f(42);               => This is from f(int)
    // f(42, 0);            => This is from f(int, int);
    // f(2.56, 3.14);       => This is from f(double, double); 

    return 0;
}
