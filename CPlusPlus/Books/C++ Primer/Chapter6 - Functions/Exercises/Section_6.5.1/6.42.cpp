#include <iostream>
#include <string>

using namespace std;

string make_plural(size_t ctr, const string &word = "s", const string &ending="s") {
    return (ctr > 1) ? word + ending : word;
}

int main(void) {
    cout << make_plural(1, "success", "s") << "\n";
    cout << make_plural(1, "failure", "s") << "\n";

    return 0;
}