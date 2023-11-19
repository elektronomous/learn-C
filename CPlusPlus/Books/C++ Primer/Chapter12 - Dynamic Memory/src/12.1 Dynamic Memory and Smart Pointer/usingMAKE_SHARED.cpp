#include <iostream>
#include <memory>
#include <vector>

using namespace std;

int main(void) {
    // shared_ptr that points to an int with value 42
    shared_ptr<int> p3 = make_shared<int>(42);

    // p4 points to a string with value "9999999999"
    shared_ptr<string> p4 = make_shared<string>(10,'9');
    
    // p5 points to an int that's value initialized to 0
    shared_ptr<int> p5 = make_shared<int>();

    // p6 points to a vector that hold string with no elements
    shared_ptr<vector<string>> p6 = make_shared<vector<string>>();
}