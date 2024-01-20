#include <iostream>

using namespace std;

struct LongDouble {
    LongDouble(double dVal = 0.0):
        d(dVal) { }

    operator double() const { return d; }
    operator float() const { return f;}

    double d = 0;
    float f = 1;
};

void calc(int) { cout << "calc(int) called." << endl; }
void calc(LongDouble d) { cout << "calc(LongDouble) called" << endl; }

int main(void) {
    // 14.50.txt
    LongDouble ldObject;
    // float ex2 = ldObject;
    // int ex1 = ldObject;
    // 14.51.txt
    double dval = 10.60;
    calc(LongDouble(dval));
    

    return 0;
}