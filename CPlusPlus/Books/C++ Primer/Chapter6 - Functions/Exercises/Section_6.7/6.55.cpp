#include <iostream>
#include <vector>

using namespace std;

inline int add(int num1, int num2) {
    return num1 + num2;
}
inline int subtract(int num1, int num2) {
    return num1 - num2;
}
inline int multiply(int num1, int num2) {
    return num1 * num2;
}
inline int divide(int num1, int num2) {
    return num1 / num2;
}

vector<int (*)(int,int)> calculator {add, subtract, multiply, divide};

