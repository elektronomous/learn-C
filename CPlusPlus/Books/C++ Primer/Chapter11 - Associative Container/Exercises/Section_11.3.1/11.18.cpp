#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(void) {
    map<string, int> word_count {{"faza", 5}, {"akbar", 7}};

    // get an iterator positioned on the first element
    map<string, int>::const_iterator map_it = word_count.cbegin();

    // compare the current iterator to the off-the-end iterator
    while (map_it != word_count.cend()) {
        cout << map_it->first << " occurs " << map_it->second << " times" << endl;
        map_it++;
    }

    return 0;
}