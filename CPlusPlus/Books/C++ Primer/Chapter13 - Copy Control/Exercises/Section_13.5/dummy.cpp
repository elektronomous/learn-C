#include <iostream>

using namespace std;

void print(const char c[]) {
    const char *start = c;
    for (;;start++){
        cout << *start << endl;
        if (*start == '\0') break;
    }
}

int main(void) {
    print("hello there");
    
    return 0;
}