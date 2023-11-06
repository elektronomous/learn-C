#include <iostream>
#include <utility>  // pair
#include <vector>
#include <string>
#include <iterator>

using namespace std;

int main(void) {
    istream_iterator<string> 
    istringstream inputString
    vector<pair<string, int>> vPairs;

    while (inputPairs != eof_inputPairs) {
        vPairs.push_back(*inputPairs++);
    }

    cout << "The pairs value from vectors: " << endl;
    for (const pair<const string, int> thePair: vPairs)
        cout << thePair.first << " " << thePair.second << endl;
    
    return 0;

}