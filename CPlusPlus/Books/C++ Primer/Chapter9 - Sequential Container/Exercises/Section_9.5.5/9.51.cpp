#include <iostream>
#include "9.51.hpp"

using namespace std;

int main(void) {
    Date d("12/1/2019");

    cout << d.getDay() << endl;
    cout << d.getMonth() << endl;
    cout << d.getYear() << endl;
    
    return 0;
}
