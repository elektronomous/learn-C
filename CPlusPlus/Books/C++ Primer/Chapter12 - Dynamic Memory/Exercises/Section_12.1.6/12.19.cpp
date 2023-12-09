#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class StrBlobPtr;
class StrBlob;

// StrBlobPtr throws an exception on attempts to access a nonexistent element
class StrBlobPtr {
    public:
        StrBlobPtr(): curr(0) { }   // implicit null to wptr
        StrBlobPtr(StrBlob &a, size_t sz = 0);
        
        string& deref() const;
        StrBlobPtr& incr();     // prefix version
    
    private:
        // check returns a shared_ptr to the vector if the check succeeds
        shared_ptr<vector<string>> check(size_t, const string &) const;

        // store a weak_ptr which means underlying vector might be destroyed
        weak_ptr<vector<string>> wptr;  
        size_t curr;                    // current position within the array

};

shared_ptr<vector<string>> StrBlobPtr::check(size_t sz, const string &msg) const {
    shared_ptr<vector<string>> pointToVec = wptr.lock();

    if (!pointToVec)    // if null
        throw runtime_error("Unbound StrBlobPtr");

    if (sz >= pointToVec->size())   // if 
        throw out_of_range(msg);
    
    return pointToVec;          // otherwise return a shared_ptr to the vector
}

string& StrBlobPtr::deref() const {
    shared_ptr<vector<string>> getCurrVec = check(curr, "dereference past end");

    return (*getCurrVec)[curr];      // *p is the vector to which this object points
}

StrBlobPtr& StrBlobPtr::incr() {
    // if curr already points past the end of the continaer, can't increment it
    check(curr, "increment past end of StrBlobPtr");
    ++curr;     // advance the current state
    return *this;
}

class StrBlob {
    typedef std::vector<std::string>::size_type size_type;
    public:
        // implicitly public
        friend class StrBlobPtr;
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
        StrBlobPtr begin();         // return the StrBlobPtr to the first element
        StrBlobPtr end();           // and one past the last element

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

StrBlobPtr StrBlob::begin() {
    return StrBlobPtr(*this);   // return the new created object
}

StrBlobPtr StrBlob::end() {
    return StrBlobPtr(*this, data->size());
}

// define StrBlobPtr incomplete types
StrBlobPtr::StrBlobPtr(StrBlob &strblob, size_t sz):
            wptr(strblob.data), curr(sz) { }