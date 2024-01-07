#include <iostream>
#include "HasPtr.hpp"

using namespace std;

int main(void) {
    HasPtr hp,hp2;
    hp = std::move(hp2);
    

    return 0;
}