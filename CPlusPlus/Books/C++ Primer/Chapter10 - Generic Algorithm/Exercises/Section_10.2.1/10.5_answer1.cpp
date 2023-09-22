#include <iostream>

using namespace std;

struct myStruct {
    int a;          // => 4 Bytes
    int b;          // => 4 Bytes
    char c;         // => 1 Byte
    bool d;         // => 1 Byte
};

int main(void) {
    myStruct s;

    // Assigning values
    s.a = 5;            
    s.b = 10;           
    s.c = 'a';          
    s.d = true;         

    cout << sizeof(s) << endl;  // => 12 Byte.. why 12? it should be reserved for 2 Bytes

    // int will take 4-Byte addressing in s
    int *p = reinterpret_cast<int*>(&s);

    cout << "Get the 4-Byte addressing and access its value: " << *p << endl;

    // get the next 4-Byte addressing in s
    p++;
    cout << "After increment, the value: " << *p << endl;
    // get the next 4-Byte addressing in s
    p++;

    // get the next 1-Byte addresssing in p
    char *ch = reinterpret_cast<char*>(p);

    cout << "Get the 1-Byte addressing and access its value: " << ch << endl;
    
    return 0;
}


/*
| [ ][ ][ ][ ] | [ ][ ][ ][ ] | [ ] | [ ]
   |
  *p

  p++;          // add 4-Byte

| [ ][ ][ ][ ] | [ ][ ][ ][ ] | [ ] | [ ]
                  |
                 *p
  p++;          // add 4-Byte

| [ ][ ][ ][ ] | [ ][ ][ ][ ] | [ ] | [ ]
                                 |
                                *c

  c++;          // add 1-Byte

| [ ][ ][ ][ ] | [ ][ ][ ][ ] | [ ] | [ ]
                                       |
                                      *c

*/