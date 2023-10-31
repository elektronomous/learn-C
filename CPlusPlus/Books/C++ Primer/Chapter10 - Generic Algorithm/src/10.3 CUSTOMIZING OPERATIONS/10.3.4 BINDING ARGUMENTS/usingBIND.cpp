#include <iostream>
#include <algorithm>
#include <functional>   // bind
#include <vector>
#include <string>

using namespace std;

bool check_size(const string &s, string::size_type sz) {
    return s.size() >= sz;
}

int main(void) {
    vector<string> words {
        "which", 
        "takes", 
        "a", 
        "single", 
        "parameter", 
        "of", 
        "type", 
        "int", 
        "and", 
        "returns", 
        "a", 
        "value", 
        "of", 
        "type", 
        "int"
    };

    auto check6 = bind(check_size, placeholders::_1, 6);
    // after the check_size is the argument list,
    // you providing a placeholder to be passed later.
    // the value 6 is argument you pass to the second paramter
    // of the check_size

    cout << "Before sorting by the size of 6: " << endl;
    for_each(words.begin(), words.end(), [](const string &s) { cout << s << " "; });
    cout << endl;

    // after sort
    cout << "After sort: " << endl;
    sort(words.begin(), words.end(), [](const string &s1, const string &s2) { return s1.size() < s2.size(); });
    for_each(words.begin(), words.end(), [](const string &s) { cout << s << " "; });
    cout << endl;

    cout << "Find the first word that has length of 6: " << endl;
    vector<string>::iterator find6 = find_if(words.begin(), words.end(), check6);
    // you can also use it like this
/*  vector<string>::iterator find6 = find_if(words.begin(), words.end(), bind(check_size, placeholders::_1, 6)); 
*/

    if (find6 != words.end())
        cout << "Found: " << *find6 << endl;
    
    return 0;
}