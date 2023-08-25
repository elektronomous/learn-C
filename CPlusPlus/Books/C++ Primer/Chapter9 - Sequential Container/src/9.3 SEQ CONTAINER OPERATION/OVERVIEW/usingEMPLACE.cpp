#include <iostream>
#include <vector>
#include "Sales_data.hpp"

using namespace std;

int main(void) {
    vector<Sales_data> vecSales_data;

    // use the Sales_data constructor as the argument on the emplace;
    vecSales_data.emplace_back("978-9823434", 20, 10);
    // insert front using the Sales_data constructor
    vecSales_data.emplace(vecSales_data.begin(), "99999999", 10, 10);
    // use the Sales_data default-constructor
    vecSales_data.emplace_back();                        


    return 0;
}