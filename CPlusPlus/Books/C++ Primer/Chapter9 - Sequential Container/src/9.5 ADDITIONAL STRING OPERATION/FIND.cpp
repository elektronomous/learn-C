#include <iostream>
#include <string>

using namespace std;

int main(void) {
    string name = "Faza Akbar";
    string::size_type indexAfterFound = name.find("Faza");  // indexAfterFound = 0
    string::size_type indexNotFound = name.find("faza");    // indexNotFound = string::npos    
}