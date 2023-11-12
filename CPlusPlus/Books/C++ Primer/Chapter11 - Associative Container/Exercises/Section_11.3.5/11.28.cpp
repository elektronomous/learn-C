#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

int main(void) {
    map<string, vector<int>> strMapVint {{"Hello", {1,2,3}}, {"There", {3,4,5}}};

    map<string, vector<int>>::iterator findHello = strMapVint.find("Hello");

    return 0;
}