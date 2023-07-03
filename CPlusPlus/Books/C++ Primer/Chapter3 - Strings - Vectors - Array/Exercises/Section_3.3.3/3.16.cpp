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
        for (int &val : v1) 
            cout << val << " ";
        cout << endl;
    
    // size
    cout << "v1 size: " << v1.size() << endl;

    // (b)
    vint v2(10);

    // contents
    cout << "v2 contents: " << endl;
    if (!v2.empty())
        for (int &val : v2) 
            cout << val << " ";
        cout << endl;
    
    // size
    cout << "v2 size: " << v2.size() << endl;

    // (c)
    vint v3(10, 42);

    // contents
    cout << "v3 contents: " << endl;
    if (!v3.empty())
        for (int &val : v3) 
            cout << val << " ";
        cout << endl;
    
    // size
    cout << "v3 size: " << v3.size() << endl;

    // (d)
    vint v4{10};

    // contents
    if (!v4.empty())
        for (int &val : v4) 
            cout << val << " ";
        cout << endl;
    
    // size
    cout << "v4 size: " << v4.size() << endl;

    // (e)
    vint v5{10, 42};

    // contents
    cout << "v5 contents: " << endl;
    if (!v5.empty())
        for (int &val : v5) 
            cout << val << " ";
        cout << endl;
    
    // size
    cout << "v5 size: " << v5.size() << endl;

    // (f) =<
    vstr v6{10};

    // contents
    cout << "v6 contents: " << endl;
    if (!v6.empty())
        for (string &val : v6) 
            cout << val << " ";
        cout << endl;
    
    // size
    cout << "v6 size: " << v6.size() << endl;

    // (g)
    vstr v7{10, "hi"};
    
    // content
    cout << "v7 content: " << endl;
    if (!v7.empty())
        for (string &val : v7) 
            cout << val << " ";
        cout << endl;

    // size
    cout << "v7 size: " << v7.size() << endl;

    return 0;
    
}