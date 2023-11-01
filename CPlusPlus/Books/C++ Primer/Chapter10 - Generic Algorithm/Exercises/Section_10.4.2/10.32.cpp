#include <iostream>
#include <numeric>
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
    Sales_item total;

    // then sort the sales data;
    sort(vSales.begin(), vSales.end(), [](const Sales_item &sale1, const Sales_item &sale2) { return sale1.isbn() < sale2.isbn(); });

    // get the first iterator
    for (vector<Sales_item>::iterator track = vSales.begin(); track != vSales.end(); track++) {
        vector<Sales_item>::iterator endOfTrack;

        if ((endOfTrack = find(track + 1, vSales.end(), *track))  != vSales.end()) 
            total = accumulate(track, endOfTrack, Sales_item(track->isbn()));
        else
            total = *track;
        
        cout << total << endl;
 
    }


    return 0;
}
