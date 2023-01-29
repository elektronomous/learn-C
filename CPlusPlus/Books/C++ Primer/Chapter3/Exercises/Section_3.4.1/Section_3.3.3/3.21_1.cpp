#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;

typedef vector<int> vint;
typedef vector<string> vstr;

int main(void) {
    // (a)
    vint v1;

    // contents
    cout << "v1 contents: " << endl;
    if (!v1.empty())
        for (vint::const_iterator it = v1.cbegin(); it != v1.cend(); it++) 
            cout << *it << " ";
        cout << endl;
    
    // size
    cout << "v1 size: " << v1.size() << endl;

    // (b)
    vint v2(10);

    // contents
    cout << "v2 contents: " << endl;
    if (!v2.empty())
        for (vint::const_iterator it = v2.cbegin(); it != v2.cend(); it++) 
            cout << *it << " ";
        cout << endl;
    
    // size
    cout << "v2 size: " << v2.size() << endl;

    // (c)
    vint v3(10, 42);

    // contents
    cout << "v3 contents: " << endl;
    if (!v3.empty())
        for (vint::const_iterator it = v3.cbegin(); it != v3.cend(); it++) 
            cout << *it << " ";
        cout << endl;
    
    // size
    cout << "v3 size: " << v3.size() << endl;

    // (d)
    vint v4{10};

    // contents
    if (!v4.empty())
        for (vint::const_iterator it = v4.cbegin(); it != v4.cend(); it++) 
            cout << *it << " ";
        cout << endl;
    
    // size
    cout << "v4 size: " << v4.size() << endl;

    // (e)
    vint v5{10, 42};

    // contents
    cout << "v5 contents: " << endl;
    if (!v5.empty())
        for (vint::const_iterator it = v5.cbegin(); it != v5.cend(); it++) 
            cout << *it << " ";
        cout << endl;
    
    // size
    cout << "v5 size: " << v5.size() << endl;

    // (f) =<
    vstr v6{10};

    // contents
    cout << "v6 contents: " << endl;
    if (!v6.empty())
        for (vstr::const_iterator it = v6.cbegin(); it != v6.cend(); it++) 
            cout << *it << " ";
        cout << endl;
    
    // size
    cout << "v6 size: " << v6.size() << endl;

    // (g)
    vstr v7{10, "hi"};
    
    // content
    cout << "v7 content: " << endl;
    if (!v7.empty())
        for (vstr::const_iterator it = v7.cbegin(); it != v7.cend(); it++) 
            cout << *it << " ";
        cout << endl;

    // size
    cout << "v7 size: " << v7.size() << endl;

    return 0;
}