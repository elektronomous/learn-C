#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> process(void) {
    string expected,
           actual;
    
    if (expected.empty())
        return {};          // return an empty vector
    else if (expected == actual)
        return {"FunctionX", "okay"};
    
    return {"FunctionX", expected, actual};
}