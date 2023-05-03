#include <iostream>
#include <string>

using std::cout,
      std::cin,
      std::string,
      std::endl;

int main(void) {
    int grade;
    string resultGrade;

    while (cin >> grade) {
        resultGrade = (grade > 90) ? "high pass" :
                      (grade > 75) ? "pass"      :
                      (grade > 60) ? "low pass"  : "fail";
    }

    cout << "Conditional Operator version: ";
    cout << resultGrade << endl;

    cout << "If-statement version: ";
    if (grade > 90)
        resultGrade = "high pass";
    else if (grade > 75)
        resultGrade = "pass";
    else if (grade > 60)
        resultGrade = "low pass";
    else
        resultGrade = "fail";
    
    cout << resultGrade << endl;

    return 0;
}

/*
= I think the easiest is the if-statement version because we use
  our language to make the condition instead of using a symbol ?:
  that conditional operator has defined.
= But the disadvantage of the if-statement is we use the tremendous variable
  name on each of the condition, which is verbose rather than our succint
  conditional operator.
*/