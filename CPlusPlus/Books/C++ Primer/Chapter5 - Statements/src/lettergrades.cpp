#include <iostream>
#include <string>
#include <vector>

using std::vector,
      std::string,
      std::cout,
      std::cin,
      std::endl;

int main(void) {
    const vector<string> lettergrades = {"F", "D", "C", "B", "A", "A++"};
    string grade;
    int score = 0;

    // ask user to enter score
    cout << "Enter score: ";
    cin >> score;

    if (score < 50)
        grade = lettergrades[0];
    else {
        grade = lettergrades[(score - 50) / 10];
        // add a plus or minus
        if (score != 100){
            if (score % 10 > 7)
                grade += '+';
            else
                grade += '-';
        }
    }

    cout << "Your grade's " << grade << endl;

    return 0;

}