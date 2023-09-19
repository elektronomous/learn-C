#include <iostream>
#include <string>
#include <stack>

using namespace std;

stack<char> replaceParenthesis(const string &str, const char &newChar) {
    stack<char> stackOfWords;
    string::size_type openParenthesis = string::npos, closeParenthesis = string::npos;

    // get all characters from string
    for (string::size_type n = 0; n<str.size(); n++) {
        stackOfWords.push(str[n]);

        // search for the open parenthesis
        if (str[n] == '(')
            openParenthesis = n;
        
        // search for the close parenthesis
        if (str[n] == ')' && openParenthesis >= 0)
            closeParenthesis = n;
        

        if ((openParenthesis != string::npos) && (closeParenthesis != string::npos)) {
            // remove the words that are in '(' to ')'
            for (string::size_type x = openParenthesis;x <= closeParenthesis; x++)
                stackOfWords.pop();
            
            // insert the value of new char
            for (string::size_type x = openParenthesis;x <= closeParenthesis; x++)
                stackOfWords.push(newChar);

            // reset the openParenthesis and closeParenthesis
            openParenthesis = closeParenthesis = string::npos;
        } 
    }
    return stackOfWords;
}

int main(void) {
    stack<char> words;
    words = replaceParenthesis("Hello You(World)", '-');

    /* show the value */ 
    while (!words.empty()) {
        cout << words.top() << endl;
        words.pop();
    }


    return 0;
}