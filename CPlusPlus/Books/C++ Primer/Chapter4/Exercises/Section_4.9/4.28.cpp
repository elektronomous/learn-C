#include <iostream>

using std::cout,
      std::cin,
      std::endl;

int main(void) {
    // size of unsigned
    cout << sizeof (unsigned) << endl;                  // => 4 Byte
    cout << sizeof (short unsigned) << endl;            // => 2 Byte
    cout << sizeof (long unsigned) << endl;             // => 8 Byte

    // size of char
    cout << sizeof (char) << endl;                      // => 1 Byte
    cout << sizeof (unsigned char) << endl;             // => 1 Byte

    // size of the int
    cout << sizeof (int) << endl;                      // => 4 Byte                    
    cout << sizeof (short int) << endl;                // => 2 Byte
    cout << sizeof (long int) << endl;                 // => 8 Byte 
    cout << sizeof (long long int) << endl;            // => 8 Byte
    cout << sizeof (unsigned int) << endl;             // => 4 Byte     
    cout << sizeof (unsigned short int) << endl;       // => 2 Byte 
    cout << sizeof (unsigned long int) << endl;        // => 8 Byte
    cout << sizeof (unsigned long long int) << endl;   // => 8 Byte

    // size of float
    cout << sizeof (float) << endl;                      // => 8 Byte
    
    // size of double
    cout << sizeof (double) << endl;                    // => 8 Byte
    cout << sizeof (long double) << endl;               // => 16 Byte
    
    // size of bool
    cout << sizeof (bool) << endl;                      // => 1 Byte

    return 0;
}