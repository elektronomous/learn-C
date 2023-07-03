#include <iostream>
#include <vector>

using std::vector,
      std::cout,
      std::cin,
      std::endl;

using vint = vector<int>;

int main(void) {
    vint v {1,2,3,4,5,6}, ivec(v.size(),0);
    vint::size_type cnt = v.size();

    for (vint::size_type i = 0; i != v.size(); i++, cnt--)
        ivec[i] = cnt;

    for (int &val: ivec)
        cout << val << endl;

    return 0;
}

/*
= For-loop works by executed the first two of its statements.
    
        for (statement_1 ; statement_2 ; statement_3)
            body_statement;

  then it continues to the body statement, then statement_3.
  regardless whether the prefix or postfix is used in the 3rd statement
  of the for-loop it would be results the same value if it's used in
  body statement. Except if it's modified in the first two of the for-loop
  statement.

*/