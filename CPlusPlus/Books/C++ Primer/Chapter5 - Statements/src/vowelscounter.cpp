#include <iostream>

using std::cin,
      std::cout,
      std::endl;


int main(void) {
    unsigned aCnt = 0,
             iCnt = 0,
             uCnt = 0,
             eCnt = 0,
             oCnt = 0,
             otherCnt = 0;

    char ch;

    while (cin >> ch) {
        // if ch is a vowel, increment the appropriate counter
        switch (ch) {
            case 'a':
                aCnt++;
                break;
            case 'i':
                iCnt++;
                break;
            case 'u':
                uCnt++;
                break;
            case 'e':
                eCnt++;
                break;
            case 'o':
                oCnt++;
                break;
            // read the nonvowels:
            default:
                ++otherCnt;
                break;
        }
    }

    cout << "Number of vowel a: \t" << aCnt << endl
         << "Number of vowel i: \t" << iCnt << endl
         << "Number of vowel u: \t" << uCnt << endl
         << "Number of vowel e: \t" << eCnt << endl
         << "Number of vowel o: \t" << oCnt << endl
         << "Number of non vowels: \t" << otherCnt << endl;

    return 0;

}