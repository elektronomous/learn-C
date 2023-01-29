#include <iostream>
#include <string>
#include <vector>

using std::cout,
      std::cin,
      std::endl,
      std::vector,
      std::string;

typedef vector<int> vint;
typedef vector<string> vstr;

int main(void) {

    int arr[10];

    for (int &v : arr)
        cout << v << " ";
    cout << endl;


    return 0;
}