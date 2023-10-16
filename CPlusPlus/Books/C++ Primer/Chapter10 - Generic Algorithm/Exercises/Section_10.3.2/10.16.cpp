#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void biggies(vector<string> &vstr) {
    // first you sort the vector
    sort(vstr.begin(), vstr.end());
    // group the unique word and then erase it
    vector<string>::iterator endOfUnique = unique(vstr.begin(), vstr.end());
    vstr.erase(endOfUnique, vstr.end());

    // using stable_sort to get the vstr sorted by its size and alphabetically
    stable_sort(vstr.begin(), vstr.end(), [](const string &s1, const string &s2) { return s1.size() < s2.size(); });

    int sz = 5;
    // using find_if to get to the first element that its character has more than 5.
    vector<string>::iterator firstFive = find_if(vstr.begin(), vstr.end(), [sz](const string &s) { return s.size() >= sz; });

    // print only words that its character has more than 5.
    for_each(firstFive, vstr.end(), [](const string &s) { cout << s << " ";});
}