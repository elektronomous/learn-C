#include <iostream>
#include "ScreenWindow_mgr.hpp"

using namespace std;

int main(void) {
    Screen myScreen1(5,5,'#'),
           myScreen2(5,5,'X');
    
    Window_mgr windows;
    windows.addScreen(myScreen1);
    windows.addScreen(myScreen2);

    windows.print(0);
    cout << "\n";
    windows.print(1);
    cout << "\n";
    cout << "Clear the first screen: \n";
    windows.clear(0);

    windows.print(0);
    cout << "\n";
    windows.print(1);
    cout << "\n";

    cout << "ON SCREEN ITSELF: \n";
    myScreen1.display(cout);
    cout << "\n";
    myScreen2.display(cout);
    cout << "\n";



    return 0;
}
