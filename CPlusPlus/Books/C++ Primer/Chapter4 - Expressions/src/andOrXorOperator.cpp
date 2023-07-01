#include <iostream>

using std::cout,
      std::endl;

int main(void) {
    unsigned char b1 = 0145;    /* [0 1 1 0 0 1 0 1] */
    unsigned char b2 = 0257;    /* [1 0 1 0 1 1 1 1] */

    cout << (b1 & b2) << endl;  /* [0 0 1 0 0 1 0 1] => 37 */
    cout << (b1 | b2) << endl;  /* [1 1 1 0 1 1 1 1] => 239 */
    cout << (b1 ^ b2) << endl;  /* [1 1 0 0 1 0 1 0] => 202 */
}