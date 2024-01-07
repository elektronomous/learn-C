#include <iostream>
#include <vector>
#include "String.hpp"

using namespace std;

int main(void) {
    vector<String> vStr;

    for (int i = 0; i<5; i++) {
        vStr.push_back(std::move(String("hello")));
        cout << "The capacity of after push_back: " << vStr.capacity() << endl;
    }
    
    return 0;
}
/*
The result is only 5-times push_back:
1     Copy-constructor is called
2     Copy-constructor is called
3     Copy-constructor is called
4     Copy-constructor is called
5     Copy-constructor is called
6     Copy-constructor is called
7     Copy-constructor is called
8     Copy-constructor is called
9     Copy-constructor is called
10    Copy-constructor is called
11    Copy-constructor is called
12    Copy-constructor is called

Why? Let's us traceback:
    Remember push_back is a method and the way it works is that its parameter
    is using copy-constructor of the parameter's type. That's why you get 2
    copy-constructor printed in this way. first in the parameter type of the push_back
    method, and in the body of the method. The method is copy-initialized the vStr.

Why we get 12? Not 10? Iam sure that when the vector is reached out the 10, it reallocate
its element, and the elemetn that's exceed is the constructed memory that created by the vector

After the instruction in the 13.50.txt, I get the result:
1. Move-constructor is called       -- move
2. Move-constructor is called       -- move
3. Copy-constructor is called
4. Move-constructor is called       -- move
5. Copy-constructor is called
6. Copy-constructor is called
7. Move-constructor is called       -- move
8. Move-constructor is called       -- move
9. Copy-constructor is called
10. Copy-constructor is called
11. Copy-constructor is called
12. Copy-constructor is called

Iam sure that this copy-constructor is called because there's a reallocation, which make the vector
to reallocate all of its element. Standard library container has own terms on how it's move its 
object such as the reallocation it does. If you look at the NOTE.txt you'll find that during reallocation
vector use its copy constructor rather than move-constructor. Note that if you count the move it does 5
times, which proved that it push_back use move-constructor of the String class, and then use the copy constructor
for reallocation

Move-constructor is called
The capacity of after push_back: 1
Move-constructor is called
Copy-constructor is called
The capacity of after push_back: 2
Move-constructor is called
Copy-constructor is called
Copy-constructor is called
The capacity of after push_back: 4
Move-constructor is called
The capacity of after push_back: 4
Move-constructor is called
Copy-constructor is called
Copy-constructor is called
Copy-constructor is called
Copy-constructor is called
The capacity of after push_back: 8

*/