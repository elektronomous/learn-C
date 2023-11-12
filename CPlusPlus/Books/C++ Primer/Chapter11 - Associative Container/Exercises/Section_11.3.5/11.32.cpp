#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    multimap<string, string> authors {
        {"Faza", "Hello"},
        {"Faza", "There"},
        {"Akbar", "Aurora"},
        {"Akbar", "Make it Happen!"}
    };
  
    for_each(authors.begin(), authors.end(), [](const pair<string, string> &p) { cout << p.first << " " << p.second << endl; });

    return 0;
}