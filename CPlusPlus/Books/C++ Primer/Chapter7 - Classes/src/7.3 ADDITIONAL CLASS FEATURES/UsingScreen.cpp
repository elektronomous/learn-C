#include <iostream>
#include "Screen.hpp"

using namespace std;

int main(void) {
    Screen monitor(10, 10, '*');
    monitor.display(cout);          // calling the non const version
    const Screen anotherMonitor(5,5, '#');
    anotherMonitor.display(cout);    // calling the const version   


    return 0;
}