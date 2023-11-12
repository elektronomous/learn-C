#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(void) {
    multimap<string, string> authors;

    multimap<string, string>::iterator retFromInsert = authors.insert({"Barth, John", "Sot-weed Factor"});
    // assign another container
    retFromInsert = authors.insert({"Barth, John", "Lost in the Funhouse"});

    return 0;
}