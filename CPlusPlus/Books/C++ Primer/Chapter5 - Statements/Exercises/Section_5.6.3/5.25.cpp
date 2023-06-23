#include <iostream>

using std::cin,
      std::cout,
      std::endl;


int main(void) {
    double numb1 = 0, numb2 = 0;

    while (true) {
        try {
            std::cout << "Enter two number seperated by space: ";
            cin >> numb1 >> numb2;

            if (!numb2)
                throw std::logic_error("division by zero");
            else
                cout << numb1 / numb2 << endl;
        } catch (std::logic_error &err) {
            cout << "Error: " << err.what() << endl
                 << "Try again? Y or N: ";
            char c;

            cin >> c;
            if (!cin || c == 'n')
                break;
        }
    }
    return 0;
}