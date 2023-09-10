#include <string>
#include <iostream>

using namespace std;

string addPrefSuffix(string &name, const string &prefix, const string &suffix) {
    // prefix inserted at the beginning of the name
    name.insert(name.begin(), prefix.begin(), prefix.end());
    // insert space after the prefix
    name.insert(name.begin() + prefix.size(), ' ');
    // insert space after the name
    name.insert(name.end(), ' ');
    // suffix inserted after the name
    name.append(suffix);

    return name;
}

int main(void) {
    string myName = "Faza";
    
    cout << addPrefSuffix(myName, "Muhammad", "Akbar") << endl;

    return 0;
}