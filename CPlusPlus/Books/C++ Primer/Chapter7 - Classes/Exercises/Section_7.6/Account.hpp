#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP

#include <string>
#include <iostream>

class Account {
    friend void read(std::istream&, Account&);
    public:
        explicit Account(const std::string &yourName): name(yourName) { }
        Account(std::istream &);

        static void initRate(void);
    private:
        std::string name;
        double balance;
        static double rate;
};

void read(std::istream&,Account&);

void read(std::istream &is, Account &acc) {
    is >> acc.name >> acc.balance;
}

Account::Account(std::istream &is) {
    read(is, *this);
}

#endif