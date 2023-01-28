#include <iostream>
#include <vector>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;

int main(void) {
    vector<int> ivec;           // initialize empty vector
    vector<int> ivec2(ivec);    // copy element of the ivec to ivec2
    vector<string> words = {"Phone", "Marker", "Monitor"};  // list initialize a vector
    /* 
    OK!
    vector<string> words{"Phone", "Marker", "Monitor"}; 

    ERROR
    vector<string> words ("Phone", "Marker", "Monitor"); 
    
    */

   vector<int> intVec(10, 5);   // create ten int, each initialize to 5
   vector<string> svec(10, "Hello");    // create ten string, each initialize to "Hello"
   vector<int> vint(10);        // vector with size 10, initialize to 0

   // push_back() => add element to the vector
   for(int i = 0; i<100; i++) {
        ivec.push_back(i);
   }

   // show result
   for (int &c: ivec)
    cout << c << endl;


   return 0;

}