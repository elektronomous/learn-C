#ifndef 7_4_HPP
#define 7_4_HPP

#include <string>

// 7.4
class Person {
    private:
        std::string name,
                    address;
    public:
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

#endif