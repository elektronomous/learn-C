#include <iostream>
#include <fstream>
#include <unordered_map>

using namespace std;

unordered_map<string, string> getRules(ifstream &is) {
    unordered_map<string, string> tempRules;

    string rule_word, word;

    while (is >> rule_word) {
        getline(is, word);
        tempRules[rule_word] = word.substr(1);
    }

    return tempRules;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        cerr << argv[0] << " <rulesFile>" << endl;
        return 1;
    }

    // define rules file
    ifstream input_rules(argv[1]);

    if (input_rules.fail()) {
        cerr << argv[1] << " is invalid file." << endl;
        return 1;
    }
    
    // store the rule into unordered_map
    unordered_map<string, string> rules;

    // store the rules into the unordered_map
    rules = getRules(input_rules);

    input_rules.close();
    return 0;
}