#include <iostream>
#include <vector>

using namespace std;

class Example {
    public:
        static double rate;
        static const int vecSize = 20;
        static vector<double> vec;
};


double Example::rate = 4;
// const int Example::vecSize;
vector<double> Example::vec(vecSize);
