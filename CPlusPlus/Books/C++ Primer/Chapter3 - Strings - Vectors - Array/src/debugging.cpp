#include <iostream>
#include <string>
#include <vector>

using std::cout,
      std::cin,
      std::endl,
      std::vector,
      std::begin,
      std::end,
      std::string;

typedef vector<int> vint;
typedef vector<string> vstr;

int main(void) {

    int arr[2][3] = {1,2,3,4,5,6};

    int *toArr = std::begin(arr);

    


    return 0;
}