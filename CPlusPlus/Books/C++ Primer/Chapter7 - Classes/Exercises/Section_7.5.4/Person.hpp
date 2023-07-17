#ifndef 7_4_HPP
#define 7_4_HPP

#include <string>
#include <iostream>

// 7.4
class Person {
    // 7.21
    friend std::istream &read(std::istream &, Person &);
    friend std::ostream &print(std::ostream &, const Person&);

    public:
        // 7.15
        Person() = default;
        Person(const std::string &yourName, const std::string &yourAddr):
                name(yourName), address(yourAddr) {}
        // 7.50
        explicit Person(const std::string &yourNmae);
  
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
    
    private:
        std::string name,
                    address;
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

// 7.15
Person::Person(const std::string &yourName) {
    name = yourName;
}

#endif