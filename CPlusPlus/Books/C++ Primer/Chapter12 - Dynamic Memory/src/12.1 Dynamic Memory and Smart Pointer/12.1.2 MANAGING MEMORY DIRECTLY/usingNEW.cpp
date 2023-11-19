#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    int *pi = new int;                  // pi points to a dynamically allocated,
                                        // unnamed, uninitiailized int
    int *anotherPi = new int(1024);     // object to which anotherPi points has value 1024
    string *ps = new string(10,'9');    // *ps is "9999999999"
    // vector with ten elements with values from 0 to 9
    vector<int> *vint = new vector<int>{0,1,2,3,4,5,6,7,8,9};

    // allocate and initialize a const int
    const int *pci = new const int(1024);
    // allocate a default-initialized const empty string
    const string *pcs = new const string();

    // sometimes memory can exhausted
    int *toInt = new int;                   // if allocation fails, new throws std::bad_alloc
    int *anotherInt = new (nothrow) int;    // if allocation fails, new returns a null pointer
}