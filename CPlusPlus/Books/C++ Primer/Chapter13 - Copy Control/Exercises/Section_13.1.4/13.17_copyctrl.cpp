#include <iostream>
#include <random>

using namespace std;

class Numbered {
    public:
    
        Numbered(): mysn(genRandom()), val(10) {}
        Numbered(const Numbered &rhs):
         mysn(genRandom()),
         val(rhs.val)
         { }
        
        size_t genRandom() {
            // how to generate random number in C++
            random_device dev;
            mt19937 rng(dev());
            uniform_int_distribution<mt19937::result_type> dist(1,100);

            return dist(rng);
        }

        // data members
        size_t mysn;
        size_t val;

};


void f1(Numbered n) {
    cout << n.mysn << endl;
}

void f2(const Numbered &n) {
    cout << n.mysn << endl;
}

int main(void) {
    Numbered a, b = a, c = b;

    cout << "When calling function f1: --------------" << endl;
    f1(a);f1(b);f1(c);
    cout << "When calling function f2: --------------" << endl;
    f2(a);f2(b);f2(c);
    return 0;
}