#include <iostream>
#include <functional>
#include <map>

using namespace std;

int main(void) {
    map<string, function<int(int,int)>> calculator {
        {"+", [](int a, int b) { return a + b; } },
        {"-", [](int a, int b) { return a - b; } },
        {"*", [](int a, int b) { return a * b; } },
        {"/", [](int a, int b) { return a / b; } },
        {"%", [](int a, int b) { return a % b; } }
    };

    cout << "calculator[\"+\"](20,10)" << ": " << calculator["+"](20,10) << endl;
    cout << "calculator[\"-\"](20,10)" << ": " << calculator["-"](20,10) << endl;
    cout << "calculator[\"*\"](20,10)" << ": " << calculator["*"](20,10) << endl;
    cout << "calculator[\"/\"](20,10)" << ": " << calculator["/"](20,10) << endl;
    cout << "calculator[\"%\"](20,10)" << ": " << calculator["%"](20,10) << endl;

    return 0;
}