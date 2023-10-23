#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main(void) {
    string::size_type sz = 6;
    vector<string> words = {
        "The",
        "library",
        "defines",
        "an",
        "algorithm",
        "named",
        "count_if.",
        "Like",
        "find_if",
        "this",
        "function",
        "takes",
        "a",
        "pair",
        "of",
        "iterators",
        "denoting",
        "an",
        "input",
        "range",
        "and",
        "a",
        "predicate",
        "that",
        "it",
        "applies",
        "to",
        "each",
        "element",
        "in",
        "the",
        "given",
        "range.",
        "count_if",
        "returns",
        "a",
        "count",
        "of",
        "how",
        "often",
        "the",
        "predicate",
        "is",
        "true.",
        "Use",
        "count_if",
        "to",
        "rewrite",
        "the",
        "portion",
        "of",
        "our",
        "program",
        "that",
        "counted",
        "how",
        "many",
        "words",
        "are",
        "greater",
        "than",
        "length",
        "6."
    };

    int word_bigger_than_six = count_if(words.begin(), words.end(), [sz] (const string &word) { return word.size() >= sz; });
    cout << "How many word that's greater than 6: " << word_bigger_than_six << endl;

    return 0;
}