#include <iostream>
#include <string>

using namespace std;

int main(void) {
    string name = "faza";

    if (name.find_first_of("0.13516546546984") == string::npos)
        cout << "npos" << endl;
    return 0;
}