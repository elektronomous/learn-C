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
   int arr[] = {1,2,3,4,5};
   vector<int> arrToVint(std::begin(arr), std::end(arr));   // we can initialize array to vector, not the other.
   vector<int> subsetArrToVint(arr + 1, arr + 4);           // initialize the subset ArrToVint from arr[1] to arr[4]

   std::cout << "The array after copy to vector: ";
   for(int &arrVal: arrToVint)
     std::cout << arrVal << " ";
   cout << endl;

   // push_back() => add element to the vector
   for(int i = 0; i<100; i++) {
        ivec.push_back(i);
   }

   // show result
   for (int &c: ivec)
    cout << c << endl;

   // empty() => return true if ivec is empty; otherwise returns false
   cout << ivec.empty() << endl;    // false => 0
   cout << ivec.size() << endl;     // => 100 elements


   return 0;

}