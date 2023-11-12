#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

pair<map<string, vector<int>>::iterator, bool> &addElement(map<string, vector<int>> &theMap);

int main(void) {
    map<string, vector<int>> strMapVint;

    addElement(strMapVint);

    return 0;

}