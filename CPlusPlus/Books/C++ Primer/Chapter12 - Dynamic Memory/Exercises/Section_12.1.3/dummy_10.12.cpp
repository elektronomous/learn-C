#include <iostream>
#include <memory>

using namespace std;

void process(shared_ptr<int> ptr) {
}

int main(void) {
    shared_ptr<int> p(new int(42));
    // process(shared_ptr<int>(p));         => this call will erase p address
    process(p);
}