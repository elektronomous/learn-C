#include <iostream>
#include <cstring>
/* 
NOTE

 */


int main(void) {
    const int &i = 10;
    const int j = 20;

    int &toj = i;

    std::cout << i << std::endl;
    std::cout << toj << std::endl;
    return 0;
}