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

    multimap<string, string>::iterator beg = narutoFamily.lower_bound("Uzumaki");
    multimap<string, string>::iterator end = narutoFamily.upper_bound("Uzumaki");

        
    for (; beg != end; beg++) {
        cout << "Naruto's family: " << beg->first
             << " " << beg->second << endl;
    }




    return 0;
}