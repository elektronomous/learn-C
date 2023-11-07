#include <iostream>
#include <map>

using namespace std;

int main(void) {
    map<string, int> line {{"associative", 2}, {"when", 1}, {"this Line", 1}};
    // if you change the when to When, the first begin iterator would be When
    // because the uppercase letter would come first then the lowercase
    
    map<string, int>::iterator getFirstLine = line.begin();
    cout << getFirstLine->first << " " << getFirstLine->second << endl;

    cout << "Using while: " << endl;
    while (getFirstLine != line.end()) {        
        cout << getFirstLine->first << " " << getFirstLine->second << endl;
        getFirstLine++;
    }

    return 0;
}