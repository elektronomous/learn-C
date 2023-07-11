#include <iostream>
#include <vector>

using namespace std;

int function(int, int);

vector<int (*)(int,int)> pF;
vector<decltype(function)*> pF2;    // equivalent type

