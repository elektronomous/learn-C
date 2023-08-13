#include <iostream>
#include <vector>
#include <list>
#include <forward_list>

using namespace std;

int main(void) {
    list<string> authors = {"Milton", "Shakespare", "Austen"};
    vector<char *> articles = {"a", "an", "the"};

    list<string> anotherAuthors(authors);       // ok: types match.

    // deque<string> authList(authors);                                    // error: container type don't match
    // deque<string> authList.assign(authors.begin(), authors.end());      // OK: assign using assign member function

    // vector<string> words(articles);                                     // error: container element type dont match
    // vector<string> words.assign(articles.begin(), articles.end())       // OK: assign using assign member function

    /* When we pass iterators, there's no requirement that the container
       type be identical
    */
   forward_list<string> words(articles.begin(), articles.end());    // ok: convert char* to string

   return 0;

}