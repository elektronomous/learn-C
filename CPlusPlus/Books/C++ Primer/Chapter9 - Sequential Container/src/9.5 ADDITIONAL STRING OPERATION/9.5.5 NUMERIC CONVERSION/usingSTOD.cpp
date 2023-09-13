#include <iostream>
#include <string>

using namespace std;

int main(void) {
    string PHI = "3.14";
    string anotherPHI = "phi = 3.14";

    double string_to_double = stod(PHI);
    double string_to_double2 = stod(anotherPHI.substr(anotherPHI.find_first_of("+.0123456789")));

    cout << string_to_double << " " << string_to_double2 << endl;
}