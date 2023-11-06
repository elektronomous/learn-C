#include <iostream>
#include <iterator>
#include <list>
#include <vector>
#include <map>

using namespace std;

int main(void) {
    map<vector<int>::iterator, int> vecToInt;
    map<list<int>::iterator, int> listToInt;    

    return 0;
}

/* 
    by default the library map uses the < operator for the key to compare the keys. 
    If you go to the previous chapter, there's a kind of iterator that it's operation uses
    the same operator as the library map which is random-access iterator. The iterator for this
    random-access iteartor is iterator in vector, array, deque, and string. So the iterator for
    the list will be error because its iterator goes on bidirectional iterator.
*/
