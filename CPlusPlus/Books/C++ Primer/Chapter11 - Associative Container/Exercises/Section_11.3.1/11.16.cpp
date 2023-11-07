#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int main(void) {
    map<int, int> intMapInt {{1,1},{2,2},{3,3}};
    map<int, int>::iterator intMapInt_it = intMapInt.begin();

    cout << "Before change the value: " << endl;
    for_each(intMapInt.begin(), intMapInt.end(), [](const pair<const int, int> &p) { cout << p.first << " " << p.second << endl; });

    // using map iterator to assign a value
    while (intMapInt_it != intMapInt.end()) {
        intMapInt_it->second *= intMapInt_it->first;
        intMapInt_it++;
    }

    cout << "After change the value: " << endl;
    for_each(intMapInt.begin(), intMapInt.end(), [](const pair<const int, int> &p) { cout << p.first << " " << p.second << endl; });

    return 0;
}