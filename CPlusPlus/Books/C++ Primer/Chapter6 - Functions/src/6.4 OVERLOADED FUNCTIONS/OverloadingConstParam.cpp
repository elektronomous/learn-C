#include <iostream>
/* 

    Record lookup(Phone);
    Record lookup(const Phone);     // redeclares Record lookup(Phone);

    Record lookup(Phone *);
    Record lookup(Phone *const);    // redeclares Record lookup(Phone*);


= top-level const has no effect on the objects that can be passed to the function.
  = top-level const is indistinguishable from one without a top-level const


    Record lookup(Account&);            // function that takes a reference to Account
    Record lookup(const Account &);     // new function that takes a const reference

    Record lookup(Account*);            // new function, takes a pointer to Account
    Record lookup(const Account*);      // new function takes a pointer to Account
*/
