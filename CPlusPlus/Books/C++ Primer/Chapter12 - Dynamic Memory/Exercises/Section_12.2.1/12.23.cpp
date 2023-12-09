#include <iostream>
#include <memory>
#include <cstring>

using namespace std;

int main(void) {
    int *concateName = new int[10]{1,2,3,4,5,6,7,8,9,0};
    /* 
    const char *str1 = "Muhammad ";
    const char *str2 = "Faza Akbar";

    char *concateName = new char[strlen(str1) + strlen(str2)];
    // combine the str1 and str2

    // first combine the str1
    strncpy(concateName, str1, strlen(str1));
    // then we place the str2 after the str1
    strncpy(concateName+strlen(str1), str2, strlen(str2));

    cout << "The result after concate the Name: " << concateName << endl; */


    delete[] concateName;
    return 0;
}