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

    return 0;
}