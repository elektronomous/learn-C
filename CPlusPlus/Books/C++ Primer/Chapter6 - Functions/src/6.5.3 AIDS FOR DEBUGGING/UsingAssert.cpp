#include <iostream>
#include <cassert>
#include <string>

using namespace std;

#define THRESHOLD 25

int main(void) {
    string word = "Hello There";

    assert(word.size() > THRESHOLD);

    return 0;
}

/* 
The result:
    UsingAssert: /mnt/e/PROGRAM/learn-C/CPlusPlus/Books/C++ Primer/Chapter6 - Functions/src/6.5.3 AIDS FOR DEBUGGING/UsingAssert.cpp:12: int main(): Assertion `word.size() > THRESHOLD' failed.
    Aborted (core dumped)

= You can turn off the assert by

    $ CC -D NDEBUG main.c       # use /D with the microsoft compiler
    

*/