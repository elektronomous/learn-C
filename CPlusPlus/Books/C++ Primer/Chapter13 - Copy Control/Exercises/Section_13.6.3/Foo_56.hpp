#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Foo {
    public:
        Foo sorted() &&;
        Foo sorted() const &;
    private:
        vector<int> data;
};

Foo Foo::sorted() && {
    sort(data.begin(), data.end());
    return *this;
}

/* You can use this to comment out, using version 13.56: */
Foo Foo::sorted() const & {
    cout << "sorted() version 13.56" << endl;
    Foo ret(*this);
    return ret.sorted();
}


