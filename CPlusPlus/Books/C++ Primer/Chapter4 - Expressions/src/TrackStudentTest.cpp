#include <iostream>

using std::cout,
      std::cin,
      std::endl;

int main(void) {
    /* 
        Assume we have 30 student on each week given a quiz by
        their teacher.
    */
    unsigned short quiz = 0;

    // Student number 23 is passed the test
    quiz |= 1U << 23;

    cout << quiz << endl;

    // Oh the student number 23 had failed
    quiz &= ~(1U << 23);

    // set the student 27 to be passed the test
    quiz |= (1U << 27);

    // is the student number 27 has passed the test
    bool status = quiz & (1U << 27);

    if (status) 
        cout << "Passed the test" << endl;
    else
        cout << "Failed the test" << endl;

    return 0;
}