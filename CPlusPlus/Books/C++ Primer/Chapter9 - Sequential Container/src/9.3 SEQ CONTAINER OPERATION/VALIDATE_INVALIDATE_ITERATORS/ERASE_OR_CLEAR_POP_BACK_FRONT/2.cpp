#include <iostream>
#include <deque>
#include <string>

/*
All other iterators, references, pointers to a deque are invalidated if the 
removed elements are anywhere but the front or back. If we removed elements
at the back of the deque, the off-the-end iterator is invalidated but other
iterators, references and pointers are unnafected; They are also are unnaff
ected if we remove from the front.
*/

using namespace std;

int main(void) {
    deque<string> deqStr {"hello","apa","kabar","anda"};

    
}