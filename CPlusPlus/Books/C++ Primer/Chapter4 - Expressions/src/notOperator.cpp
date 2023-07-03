#include <iostream>

using std::cout,
      std::endl;

int main(void) {
    unsigned char bits = 0227; /* [1 0 0 1 0 1 1 1] */
    cout << ~bits << endl; /* [1 1 1 1 1 1 1 1] [1 1 1 1 1 1 1 1] [1 1 1 1 1 1 1 1] [0 1 1 0 1 0 0 0] => -152 */
}