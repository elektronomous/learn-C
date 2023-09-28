#include <iostream>
#include <forward_list>

using namespace std;

int main(void) {
    forward_list<int> flint {1,2,3,4};

    fill_n(back_inserter(flint), 5, 10);

    
}