/* why dont we read 100 at one time. */
#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    vector<char> vchr = {'w','h','y','d','o','n','t','w','e','w','a','n','t'};

    string str = string(vchr.begin(), vchr.end()).substr(0,100);

    cout << "The 100 character after reads: " << str << endl;

    return 0;
}