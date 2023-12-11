#include <iostream>
#include <string>

using namespace std;

int main(void) {
    string q = "hello";
    string text = "hello there hello";
    size_t pos = 0, nQuery = 0;

    while ((pos = text.find(q, pos)) != string::npos) { 
        nQuery++;
        pos++;
    }
    
    cout << nQuery << endl;

    return 0;
}