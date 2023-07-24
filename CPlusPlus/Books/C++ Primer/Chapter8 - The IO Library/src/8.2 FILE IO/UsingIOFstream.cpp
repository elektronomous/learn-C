#include <iostream>
#include <fstream>
#include "Sales_data.hpp"

using namespace std;

int main(int argc, char *argv[]) {
    if (argc != 3) {
        cout << "How to use the program:\n";
        cout << "UsingIOFstream <inputFile> <outputFile>\n";
        return 1;
    }

    ifstream input(argv[1]);        // open the file of the sales transactions
    ofstream output(argv[2]);       // open the output file 
    Sales_data total;


    /* = We can use object of the inherited type in places where an object
     *   of the original type is expected.
     * = That is, if we have function that takes an ostream&, we can call that
     *   function passing it an ofstream object and similarly for istream& and
     *   ifstream
     */
    if (read(input, total)) {
        Sales_data trans;

        while (read(input, trans)) {
            if (total.isbn() == trans.isbn())
                total.combine(trans);
            else {
                print(output, total) << endl;   // print the result into output file
                total = trans;
            }
        }
        print(output, total) << endl;           // print the last transaction into the outputfile
    } else
        cerr << "No Data!!\n";
    
    input.close();      // close the input file
    output.close();      // close the output file

    return 0;
}