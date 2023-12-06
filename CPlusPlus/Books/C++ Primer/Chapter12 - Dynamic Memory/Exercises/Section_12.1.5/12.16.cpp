#include <iostream>
#include <memory>

using namespace std;

int main(void) {
    unique_ptr<int> p = new int(10);
    unique_ptr<int> p2(new int());

    unique_ptr<int> p3 = p2;
}

/*
"no suitable constructor exists to convert from "int *" to "std::__1::unique_ptr<int, std::__1::default_delete<int>>""

= We can't copy because the object need a constructor, which each type of the constructor is int and default_delete<int>

"function "unique_ptr<_Tp, _Dp>::unique_ptr(const unique_ptr<int, default_delete<int>> &) [with _Tp=int, _Dp=default_delete<int>]\" (declared implicitly) cannot be referenced -- it is a deleted function",


*/