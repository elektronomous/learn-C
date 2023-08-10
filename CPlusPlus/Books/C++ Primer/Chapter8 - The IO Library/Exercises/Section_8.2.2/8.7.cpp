#include <iostream>
#include <fstream>
#include "Sales_data.hpp"

using namespace std;

int main(int argc, char *argv[]) {
    if (argc != 3) {
        cout << "How to use the program:\n";
        cout << "8.6 <inputFile> <outputFile>\n";
        return 1;
    }

    ifstream input(argv[1]);        // open the file of the sales transactions as the input stream
    ofstream output(argv[2]);       // open the file in truncated mode and out mode
    Sales_data total;


    /* 
     * = We can use object of the inherited type in places where an object
     *   of the original type is expected.
     * = That is, if we have function that takes an ostream&, we can call that
     *   function passing it an ofstream object and similarly for istream& and
     *   ifstream
     */
    read(input, total);
    output << "ISBN\tSELL\tINCOME\tPRICE\n";
    print(output, total) << "\n";
    
    input.close();      // close the input file
    output.close();     // close the output file

    return 0;
}