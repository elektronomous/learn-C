#include <iostream>

using std::cout,
      std::cin,
      std::endl;


int main(void) {
    int aCnt = 0,
        iCnt = 0,
        uCnt = 0,
        eCnt = 0,
        oCnt = 0,
        otherCnt = 0;
    char ch;

    while (cin >> ch) {
        if (ch == 'a' or ch == 'A')
            aCnt++;
        else if (ch == 'i' or ch == 'I')
            iCnt++;
        else if (ch == 'u' or ch == 'U')
            uCnt++;
        else if (ch == 'e' or ch == 'E')
            eCnt++;
        else if (ch == 'o' or ch == 'O')
            oCnt++;
        else
            otherCnt++;
    }

    cout << "Number of vowels a: " << aCnt << endl
         << "Number of vowels i: " << iCnt << endl
         << "Number of vowels u: " << uCnt << endl
         << "Number of vowels e: " << eCnt << endl
         << "Number of vowels o: " << oCnt << endl
         << "Number of non-vowels: " << otherCnt << endl;

    return 0;
}