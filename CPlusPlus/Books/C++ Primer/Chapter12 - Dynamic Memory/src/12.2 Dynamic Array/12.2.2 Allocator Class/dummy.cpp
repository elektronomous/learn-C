#include <iostream>
#include <memory>

using namespace std;

int main(void) {
    int *pX = nullptr;

    if (!pX)
        cout << "pX is nullptr" << endl;
    
    return 0;
}