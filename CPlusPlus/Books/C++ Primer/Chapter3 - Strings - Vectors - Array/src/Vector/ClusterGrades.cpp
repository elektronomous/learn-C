#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main(void) {
    // create 11 cluster of grades: 0-9, 10-19, 20-29, 30-39, ... 90-99, 100
    vector<unsigned> clusters(11, 0);
    unsigned grade = 0;

    // prompt user to enter grades
    cout << "Enter grades: " << endl;
    while (cin >> grade) {
        // don't worry if the vector is out of range. we only
        // subcript the grade by 10 and divided by 100
        if (grade <= 100) 
            ++clusters[grade/10];
    }

    // show result
    cout << "Clusters: " << endl;
    for (unsigned &val : clusters) 
        cout << val << " ";
    cout << endl;

    return 0;
}