#include <iostream>

using namespace std;

void ff(int*);
void ff(unsigned int);

void (*pf1)(unsigned int) = ff;     // point to ff(unsigned int)