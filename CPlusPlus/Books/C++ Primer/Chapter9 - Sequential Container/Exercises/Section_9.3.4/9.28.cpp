#include <iostream>
#include <forward_list>

using namespace std;

void funct(forward_list<string> &fl, const string &s1, const string &s2) {
    forward_list<string>::iterator flPrev = fl.before_begin();
    forward_list<string>::iterator flCurr = fl.begin();

    while (flCurr != fl.end()) {
        if (*flCurr ==  s1){
            // move forward the flPrev
            flPrev = flCurr;
            // move forward the flCurr
            flCurr = fl.insert_after(flCurr, s2);   // return to the last inserted element
            break;
        } else
            flPrev = flCurr;

        flCurr++; 
    }

    if (flCurr == fl.end())
        fl.insert_after(flPrev, s2);
}

int main(void) {
    forward_list<string> flstr {"muhammad","akbar"};
    funct(flstr, "anggun", "faza");

    cout << "The flstr contains: ";
    for (const string &str: flstr)
        cout << str << " ";
    cout << endl;

    return 0;
}