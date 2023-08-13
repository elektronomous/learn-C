#include <iostream>
#include <list>
#include <vector>
#include <string>

using namespace std;

int main(void) {
    list<char *> lists {"Hello", "there"};
    vector<string> vstr;

    vstr.assign(lists.begin(), lists.end());

    return 0;
}