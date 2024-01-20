#include <iostream>

using namespace std;

 struct LongDouble { 
    // member operator+ for illustration purposes; + is
    // usually a nonmember
    LongDouble operator+(const SmallInt&);
    LongDouble(double = 0.0);
    operator double();
    operator float();
};
class SmallInt {
    friend SmallInt operator+(const SmallInt&, const SmallInt&);
public:
    SmallInt(int = 0);                      // conversion from int
    operator int() const { return val; }    // conversion to int
private:
    std::size_t val;
};

int main(void) {
    LongDouble operator+(LongDouble, double);
    SmallInt si;
    LongDouble ld; 
    ld = si + ld;
    ld = ld + si;
    double d = si.operator int() + 3.14;

    return 0;
}