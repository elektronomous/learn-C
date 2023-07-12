#ifndef 7_4_HPP
#define 7_4_HPP

#include <string>
#include <iostream>

// 7.4
class Person {
    public:
        std::string name,
                    address;
    
        /*
            7.5:
            since these two functions are only return a value,
            we don't modify anything. so we decided to use const
            after the parameter list to make this function as
            const member function.
        */
        std::string getName(void) const {
            return name;
        }

        std::string getAddress(void) const {
            return address;
        }
};

// 7.9
std::istream &read(std::istream &is, Person &person) {
    is >> person.name >> person.address;

    return is;
}

std::ostream &print(std::ostream &os, const Person &person) {
    os << person.name << " " << person.address;

    return os;
}

#endif