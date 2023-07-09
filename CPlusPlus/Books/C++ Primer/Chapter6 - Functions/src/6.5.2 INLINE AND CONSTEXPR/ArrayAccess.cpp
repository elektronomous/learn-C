#include <iostream>

using namespace std;


constexpr int new_sz() {
    return 42;
}

constexpr size_t scale(size_t cnt) {
    return new_sz() * cnt;
}

/* 
= If you pass to scale a literal value, it will return constexpr type value
= If you pass to scale an object value, like 
        
        int i = 2, scale(i)
  The compiler will give you an error
*/

int main(void) {
    int arr[new_sz()] = {1,2,3,4,5};
    constexpr int foo = new_sz();

    cout << arr[0] << " " << foo << "\n";

    return 0;
}