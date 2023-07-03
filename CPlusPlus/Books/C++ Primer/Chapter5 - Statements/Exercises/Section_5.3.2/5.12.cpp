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
        ffCnt = 0,
        flCnt = 0,
        fiCnt = 0,
        otherCnt = 0;
    bool fstatus = false;
    string str;

    while (getline(cin, str)) {
        for (const char &ch: str) {
            if (fstatus){
                if (ch == 'f')
                    ffCnt++;
                else if (ch == 'l')
                    flCnt++;
                else if (ch == 'i')
                    fiCnt++;
                
                fstatus = false;
            }

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
            else if (ch == 'f')
                fstatus = true;
            else
                otherCnt++;
        }
    }

    cout << "Number of vowels a: " << aCnt << endl
         << "Number of vowels i: " << iCnt << endl
         << "Number of vowels u: " << uCnt << endl
         << "Number of vowels e: " << eCnt << endl
         << "Number of vowels o: " << oCnt << endl
         << "Number of ff-characters: " << ffCnt << endl
         << "Number of fl-characters: " << flCnt << endl
         << "Number of fi-characters: " << fiCnt << endl
         << "Number of non-vowels: " << otherCnt << endl
         << "Number of blank spaces: " << blankCnt << endl;

    return 0;
}