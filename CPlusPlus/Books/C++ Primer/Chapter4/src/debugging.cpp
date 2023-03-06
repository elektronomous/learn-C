#include <iostream>
#include <climits>

int& changeObject(int &object) {
    object++;

    return object;
}

int main(void) {
    
    const char *cp = "";

    if(*cp) {
        std::cout << "string";
    }else {
        std::cout << "empty";
    }

    return 0;

}