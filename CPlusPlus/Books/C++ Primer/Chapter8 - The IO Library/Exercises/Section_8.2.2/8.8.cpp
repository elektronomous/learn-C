#include <iostream>
#include <fstream>
#include "Sales_data.hpp"

using namespace std;

int main(int argc, char *argv[]) {
    if (argc != 3) {
        cerr << "HOW TO USE PROGRAM:\n"
             << argv[0] << " <inputFile> <outputFile>\n";
        return 1;
    }

    ifstream inputSales_data(argv[1]);       // open the first file as in
    // check the input file
    if (inputSales_data.fail()) {
        cerr << "Invalid input file.\n";
        return 1;
    }

    ofstream outputSales_data(argv[2], ofstream::app);      // open the output program in out mode and append mode
    // check the output file
    if (outputSales_data.fail()) {
        cerr << "Invalid output file.\n";
        return 1;
    }

    // create Sales_data Object
    Sales_data total;

    // read inputSales_data and pass its result to total object
    read(inputSales_data, total);
    
    // output its content to output file
    if (!outputSales_data.tellp())
        outputSales_data << "ISBN\tSELL\tINCOME\tPRICE\n";  // create a header if the position of pointer is 0
    print(outputSales_data, total);
    outputSales_data << "\n";

    inputSales_data.close();
    outputSales_data.close();

    return 0;
}