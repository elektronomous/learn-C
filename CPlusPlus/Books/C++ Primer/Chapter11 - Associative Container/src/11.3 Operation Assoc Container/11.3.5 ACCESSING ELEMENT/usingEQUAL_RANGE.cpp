#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(void) {
    multimap<string, string> narutoFamily {
        {"Haruno", "Sakura"},
        {"Nara", "Sikamaru"},
        {"Nara", "Sikadai"},
        {"Uzumaki", "Naruto"},
        {"Uzumaki", "Boruto"},
        {"Uzumaki", "Himawari"},
        
    };

    pair<multimap<string, string>::iterator, multimap<string, string>::iterator> pos;
    pos = narutoFamily.equal_range("Uzumaki");

    // pos.first is equivalent to beg, and pos.second is equivalent to end
    for (; pos.first != pos.second; pos.first++) {
        cout << "Naruto's family: " << pos.first->first
             << " " << pos.first->second << endl;
    }




    return 0;
}