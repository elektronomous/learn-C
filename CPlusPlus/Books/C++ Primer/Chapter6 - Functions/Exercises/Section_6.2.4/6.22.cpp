#include <iostream>

using std::cin,
      std::cout,
      std::endl;

void swap(int *num1, int *num2) {
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

int main(void) {

    int i = 5, j = 10;

    cout << "Before i and j are swept: " << i << " and " << j << endl;
    swap(&i, &j);
    cout << "After i and j are swept: " << i << " and " << j << endl;
    
    return 0;
}

/* using the reference is the easier */