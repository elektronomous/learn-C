#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP

#include <iostream>
#include <string>

class Account {
    public:
    /* Member functions can use static members directly, without scope operator */
        void calculate(void) { amount += amount * interestRate; }

        /* = static member functions are not bound to any object; they do not
             have a this pointer. As a result, static member functions may not
             be declared as const and we may not refer to this in the of a static
             member
        */
        static double rate(void) { return interestRate; }
        static void rate(double);
    private:
    /* = Object do not contain data associated with static data members.
         Each Account object only contain two data members: owner & amount */
        std::string owner;
        double amount;
    
    /* = because static data members are not part of inidividual objects of the class type,
         they are not defined when we create objects of the class. As a result, they are not
         initialized by the class' constructors.
    */
        static double interestRate;
        static double initRate();
};

/* static keyword only appears with the declaration inside the class body */
void Account::rate(double newRate) {
    interestRate = newRate;
}

double Account::initRate() {
    return 0;
}

/* = in general, we may not initialize a static member inside the class. 
     Instead, we must define and initialize each static data member outside 
     the class body.
*/
double Account::interestRate = initRate();
#endif