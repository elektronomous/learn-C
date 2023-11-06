#include <iostream>
#include <utility>  // pair
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main(void) {
    string lineOfString;
    vector<pair<string, int>> vPairs;

    cout << "Enter a string and a int in sequence order(aa 1 bb 3..): " << endl;
    while (getline(cin, lineOfString)) {
        // we create the pair right here
        string key;
        int val;

        istringstream inputString(lineOfString);
        inputString >> key;
        inputString >> val;
        vPairs.push_back({key, val});
    }

    cout << "The pairs value from vectors: " << endl;
    for (const pair<const string, int> thePair: vPairs)
        cout << thePair.first << " " << thePair.second << endl;
    
    return 0;

}