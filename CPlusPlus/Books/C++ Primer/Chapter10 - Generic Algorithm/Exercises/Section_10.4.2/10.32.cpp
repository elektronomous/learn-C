#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
#include "Sales_item.h"

using namespace std;

bool compareIsbn(const string &isbn1, const string &isbn2) {
    return isbn1 <= isbn2;
}

int main(void) {
    cout << "Enter Sales item: " << endl;
    istream_iterator<Sales_item> inputSales(cin), eof_inputSales;
    vector<Sales_item> vSales(inputSales, eof_inputSales);
}
