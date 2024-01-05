#include <iostream>

using namespace std;

class Dummy {
    public:
        Dummy(int n):
            number(n) {}
        
        Dummy& operator=(const Dummy &rhs) {
            changeNumber();
            cout << "This number: " << number << endl;
            cout << "Rhs number: " << rhs.number << endl;

            return *this;
        }
        
        int number = 0;

    private:
        void changeNumber() { number = 100;}
};

void testing(int *n) { cout << "The number you've passed: " << n << endl;}

int main(void) {
    Dummy d1(10);
    int n = 30;
    d1 = d1;


    return 0;
}