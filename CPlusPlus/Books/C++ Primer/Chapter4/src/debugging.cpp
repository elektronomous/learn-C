#include <iostream>
#include <vector>

using std::cout,
      std::cin,
      std::endl,
      std::vector,
      std::string;

int main(void) {
    int x[10];       int *p = x;
    
    for (int i = 0; i < 10; i++)
        cout << x[i] << endl;
    cout << sizeof (x)/sizeof (*x) << endl;
    cout << sizeof (p)/sizeof (*p) << endl;

    return 0;
}

/*

0000 0011
1111 1100
1111 1101

 */