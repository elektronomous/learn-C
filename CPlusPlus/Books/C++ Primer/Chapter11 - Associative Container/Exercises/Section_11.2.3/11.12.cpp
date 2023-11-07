#include <iostream>
#include <utility>  // pair
#include <algorithm>
#include <vector>
#include <string>
#include <iterator>

using namespace std;

int main(void) {
    vector<pair<string, int>> vPairs;
    string inputStr;
    int inputInt;

    // enter the string first to the vector
    cout << "Input string then number: " << endl;
    while (cin >> inputStr) {
        cin >> inputInt;
        vPairs.push_back({inputStr, inputInt});
    }

    for_each(vPairs.cbegin(), vPairs.cend(), [](const pair<const string, int> &p) { cout << "The string : " << p.first << " - " << p.second << endl;});

    
    return 0;

}