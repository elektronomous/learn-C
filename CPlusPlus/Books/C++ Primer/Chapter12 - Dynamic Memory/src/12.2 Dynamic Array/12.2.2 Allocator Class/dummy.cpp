#include <iostream>
#include <memory>

using namespace std;

int main(void) {
    allocator<string> allocStr;
    string *pStr = allocStr.allocate(10);
}