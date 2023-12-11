#include <iostream>

using namespace std;

class dummy1;
class dummy2;

class dummy1 {
    public:
        dummy1() = default;
        dummy1(dummy2 *d2):
            pointToDummy2(d2) {}

        void connectToD2(dummy2 *d2) {
            pointToDummy2 = d2;
        }

        dummy2* pointToDummy2;
};

class dummy2 {
    friend class dummy1;
    public:
        dummy2() = default;
        dummy2(int i):
            value(i) {}
        
        dummy1 connectD1ToD2(int i) {    
            return dummy1(this);
        }

        int getValue(void) const {
            return value;
        }
    
    private:
        int value = 10;
};

int main(void) {
    return 0;
}

