#include <iostream>

using std::cout,
      std::endl;

int main(void) {
    // 0233 is an octal literal
    unsigned char bits = 0233;  /* [1 0 0 1 1 0 1 1] */

    cout << (bits << 8) << endl; /* [1 0 0 1 1 0 1 1] [0 0 0 0 0 0 0 0] => 39680 decimal */
    cout << (bits << 31) << endl; /* [1 0 0 0 0 0 0 0] [0 0 0 0 0 0 0 0] [0 0 0 0 0 0 0 0] [0 0 0 0 0 0 0 0] => 524288 decimal */
    cout << (bits >> 3) << endl; /* [0 0 0 1 0 0 1 1] => 19 */
}