#include <vector>
#include <memory>
#include <iostream>

class StrBlob {
    public:
        typedef std::vector<std::string>::size_type size_type;
        StrBlob();
        StrBlob(std::initializer_list<std::string> il);
        size_type size() const { return data->size(); }
        bool empty() const { return data->empty(); }
        // add and remove elements
        void push_back(const std::string &t) { data->push_back(t); }
        
        void pop_back();
        // element access
        std::string& front() const;
        std::string& back() const;
    
    private:
        std::shared_ptr<std::vector<std::string>> data;
        // throws msg if data[i] isn't valid
        void check(size_type i, const std::string &msg) const;
};

// constructor
StrBlob::StrBlob(): data(std::make_shared<std::vector<std::string>>()) { }
StrBlob::StrBlob(std::initializer_list<std::string> il): data(std::make_shared<std::vector<std::string>>(il)) { } 

// check private member
void StrBlob::check(size_type i, const std::string &msg) const {
    if (i >= data->size())
        throw std::out_of_range(msg);       
}

// access elements
std::string& StrBlob::front() const {
    // if the vector is empty, check will throw
    check(0, "front on empty StrBlob");
    return data->front();
}

std::string& StrBlob::back() const {
    // if the vector is empty, check will throw
    check(0, "back on empty StrBlob");
    return data->back();
}

void StrBlob::pop_back() {
    // if the vector is empty, check will throw
    check(0, "pop_back on empty StrBlob");
    data->pop_back();
}