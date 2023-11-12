#include <iostream>
#include <map>
#include <utility> // pair

using namespace std;

int main(void) {
    map<string, int> word_count;

    // four-ways to insert an element to a map:
    word_count.insert({"faza", 1});
    word_count.insert(make_pair("akbar", 2));
    word_count.insert(pair<string, int>("muhammad", 3));
    word_count.insert(map<string, int>::value_type("Anggun", 1));

    return 0;
}