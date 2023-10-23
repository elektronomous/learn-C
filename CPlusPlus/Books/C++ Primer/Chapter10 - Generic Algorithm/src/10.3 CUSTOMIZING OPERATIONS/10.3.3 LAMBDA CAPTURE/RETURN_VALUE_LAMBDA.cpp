#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    vector<int> vint {-1, 9, -5, -10, 2, 3};

    cout << "Before replace: " << endl;
    for_each(vint.begin(),vint.end(), [](const int &val) { cout << val << " ";});
    cout << endl;

    /*
        replace with transform() algorithm function.
        The transform function takes three iterators and a callable. The first two iterators
        denote an input sequence and the third is a destination. The algorithm calls the
        given callable on each element in the input sequence and writes the result to the
        destination. As in this call, the destination iterator can be the same as the iterator
        denoting the start of the input. When the input iterator and the destination iterator
        are the same, transform replaces each element in the input range with the result
        of calling the callable on that element
    */
    cout << "After replace: " << endl;
    /*
        transform(vint.begin(), vint.end(), vint.begin(), [](int i) { return (i < 0) ? -i : i; });

        - When you use return statement, it must be something would be returned. From the statement
          you see after the return, it's a condition and when you return a condition, you're returning
          a bool value.
    */
    transform(vint.begin(), vint.end(), vint.begin(), [](int i) -> int { if (i < 0) return -i; else return i;});
    /*
        - Now if you confused why we need to include return type in the above statement? Because if statement isn't
          always return statement, if statement doesn't return anything, it could be use to return statement but the
          major functionality of the if statement isn't for return value.
    */
    for_each(vint.begin(), vint.end(), [](const int &i) { cout << i << " "; });

    return 0;
}