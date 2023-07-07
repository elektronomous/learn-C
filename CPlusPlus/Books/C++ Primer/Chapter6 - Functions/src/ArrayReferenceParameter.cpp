#include <iostream>

using std::cin,
      std::cout,
      std::endl;

// function definion
void print(int (&)[]);

void print(int (&arr)[5]) {     // you can't fill empty in brackets 
    for (int &val: arr)
        cout << val << "\n";
}

int main(void) {
    int j[5] = {1,2,3,4,5};

    print(j);       // j is converted automatically to an int* points to j[0]

    return 0;
}