#include <iostream>
#include <string>

using std::cout,
      std::cin,
      std::string,
      std::endl;


int main(void) {
    int aCnt = 0,
        iCnt = 0,
        uCnt = 0,
        eCnt = 0,
        oCnt = 0,
        blankCnt = 0,
        otherCnt = 0;
    string str;

    while (getline(cin, str)) {
        for (const char &ch: str) {
            if (ch == 'a' || ch == 'A')
                aCnt++;
            else if (ch == 'i' || ch == 'I')
                iCnt++;
            else if (ch == 'u' || ch == 'U')
                uCnt++;
            else if (ch == 'e' || ch == 'E')
                eCnt++;
            else if (ch == 'o' || ch == 'O')
                oCnt++;
            else if (ch == ' ' || ch == '\t' || ch == '\n')
                blankCnt++;
            else
                otherCnt++;
        }
    }

    cout << "Number of vowels a: " << aCnt << endl
         << "Number of vowels i: " << iCnt << endl
         << "Number of vowels u: " << uCnt << endl
         << "Number of vowels e: " << eCnt << endl
         << "Number of vowels o: " << oCnt << endl
         << "Number of non-vowels: " << otherCnt << endl
         << "Number of blank spaces: " << blankCnt << endl;

    return 0;
}