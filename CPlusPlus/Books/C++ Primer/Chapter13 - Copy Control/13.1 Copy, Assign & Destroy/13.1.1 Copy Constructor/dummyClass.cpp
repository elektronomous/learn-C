#include <iostream>
#include <string>

using namespace std;

class DummyClass {
    public:
        DummyClass(int i):
            val(i) { }
        DummyClass(std::string s):
            strVal(s) { }
        
        void showVal(void) const {
            cout << "The integer: " << val
                 << "\nThe string: " << strVal << endl;
        }
    private:
        int val;
        std::string strVal;
};

int main(void) {
    DummyClass d1 = 10;
    /*
    The compiler automatically create a temporary object using the first constructor
    of the DummyClass
        DummyClass d1 = 10;  => DUmmyClass d1 = DummyClass(10);
    
    now if you make the first constructor explicit, then the compiler won't do that for us.
    The only way to copy DummyClass object which its value is 10 is by explicityly create
    that temporary object
        DummyClass d1 = DummyClass(10);
    */
    DummyClass d2 = string("Hello");

    d1.showVal();
    d2.showVal();

    return 0;

}