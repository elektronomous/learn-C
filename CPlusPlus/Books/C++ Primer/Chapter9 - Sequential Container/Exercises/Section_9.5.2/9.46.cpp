#include <iostream>
#include <string>

using namespace std;

string addPrefSuffix(string &name, const string &prefix, const string &suffix) { 
    // first insert the prefix
    name.insert(name.begin(), prefix.begin(), prefix.end());
    // then insert after the rpelace a space
    name.insert(name.begin() + prefix.size(), ' ');

    // insert now space at the end of the name, so suffix would be
    // clear when reading
    name.insert(name.begin() + name.size(), ' ');               // we also could use name.end(), but the exercise ask us to use the length
    name.insert(name.begin() + name.size(), suffix.begin(), suffix.end());

    return name;
}

int main(void) {
    string myName = "Faza";
    cout << "The name after added prefix & suffix: " << addPrefSuffix(myName, "Muhammad", "Akbar") << endl;

    return 0;
}