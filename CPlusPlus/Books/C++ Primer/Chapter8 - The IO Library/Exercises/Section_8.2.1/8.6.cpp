#include <iostream>
#include <fstream>
#include "Sales_data.hpp"

using namespace std;

int main(int argc, char *argv[]) {
    if (argc != 2) {
        cout << "How to use the program:\n";
        cout << "8.6 <inputFile>\n";
        return 1;
    }

    ifstream input(argv[1]);        // open the file of the sales transactions as the input stream
    Sales_data total;


    /* 
     * = We can use object of the inherited type in places where an object
     *   of the original type is expected.
     * = That is, if we have function that takes an ostream&, we can call that
     *   function passing it an ofstream object and similarly for istream& and
     *   ifstream
     */
    read(input, total);
    cout << "ISBN\tSELL\tINCOME\tPRICE\n";
    print(cout, total) << "\n";
    
    input.close();      // close the input file

    return 0;
}