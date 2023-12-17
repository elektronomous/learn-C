#include <iostream>
#include <random>

using namespace std;

class Employee {
    public:
        Employee() = default;
        Employee(string n): name(n) { }

    private:
        // data members
        string name;
        static size_t id;
};

/*
Moreover, in general, we may not initialize a static member inside the class. 
Instead, we must define and initialize each static data member outside the class body
*/
size_t Employee::id = 0;