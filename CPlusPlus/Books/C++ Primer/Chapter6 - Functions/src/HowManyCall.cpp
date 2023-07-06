#include <iostream>

using std::cin,
      std::cout,
      std::endl;

size_t count_calls() {
    static size_t ctr = 0;  // variable will persist accross calls
    return ++ctr;
}
int main(void) {
    for (size_t i = 0; i < 10; i++)
        cout << count_calls() << endl;
    
    return 0;
}