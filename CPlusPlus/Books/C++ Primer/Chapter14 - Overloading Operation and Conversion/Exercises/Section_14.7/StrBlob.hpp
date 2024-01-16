#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class StrBlobPtr;
class StrBlob;

// StrBlobPtr throws an exception on attempts to access a nonexistent element
class StrBlobPtr {
    // 14.16.txt
    friend bool operator==(const StrBlobPtr &, const StrBlobPtr &);
    friend bool operator!=(const StrBlobPtr &, const StrBlobPtr &);
    // 14.18.txt
    friend bool operator<(const StrBlobPtr &, const StrBlobPtr &);
    // 14.28.txt
    friend StrBlobPtr operator+(const StrBlobPtr &, const int &);
    friend StrBlobPtr operator-(const StrBlobPtr &, const int &);

    public:
        StrBlobPtr(): curr(0) { }   // implicit null to wptr
        StrBlobPtr(StrBlob &a, size_t sz = 0);
        
        string& deref() const;
        StrBlobPtr& incr();     // prefix version

        // 14.26.txt
        string& operator[] (size_t n) { return wptr.lock()->at(n); }
        const string& operator[] (size_t n) const { return wptr.lock()->at(n); }

        // 14.6 Increment & Decrement Operators
        StrBlobPtr& operator++();       // prefix operator
        StrBlobPtr& operator--();

        StrBlobPtr operator++(int);    // postfix operator
        StrBlobPtr operator--(int);

        // 14.7 Member Access Operators
        string& operator*() const {
            shared_ptr<vector<string>> getAddr = check(curr, "dereference past end");
            return (*getAddr)[curr];

            /* If you wonder that how to return string& while the implicit parameter
               is pointer to const StrBlobPtr, you can't change its object state right?
               = If you read the code, the check function return shared_ptr<vector<string>>
                 which is there's no relation with the object being modified here. so we can
                 assign another string by dereference this object (look dummy.hpp).
            */
        }

        string* operator->() const {
            return &this->operator*();
        }
        /* how this operator works, then visit the dummy.hpp:
                p->size();      // as the point-> mem execution follows:
                                // 1. return object of a class which is string*
                                // 2. string* is used to fetch mem (strObject->mem)
                                // 3. strObject->mem return the built-in pointer which
                                      can be used to fetch mem.
        */

        
    
    private:
        // check returns a shared_ptr to the vector if the check succeeds
        shared_ptr<vector<string>> check(size_t, const string &) const;

        // store a weak_ptr which means underlying vector might be destroyed
        weak_ptr<vector<string>> wptr;  
        size_t curr;                    // current position within the array

};

// 14.16.txt
bool operator==(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
    // if it's point to the same object
    return (lhs.wptr.lock() == rhs.wptr.lock());
}

// 14.16.txt
bool operator!=(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
    return !(lhs == rhs);
}

// 14.18.txt
bool operator<(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
    // you always get undefined value on either object evaluated to be less-than
    // because this is a pointer
    return (lhs.wptr.lock() < rhs.wptr.lock());
}

// 14.6 Increment & Decrement Operators
StrBlobPtr& StrBlobPtr::operator++() {
    // if curr already points past the end of the container, can't increment it 
    check(curr, "increment past end of the StrBlobPtr");
    curr++;
    return *this;
}

StrBlobPtr operator+(const StrBlobPtr &lstr, const int &n) {
    StrBlobPtr ret = lstr;
    ret.curr += n;

    return ret;
}

StrBlobPtr operator-(const StrBlobPtr &lstr, const int &n) {
    StrBlobPtr ret = lstr;
    ret.curr -= n;

    return ret;
}

StrBlobPtr& StrBlobPtr::operator--() {
    // if curr is zero, decrementing it will yield an invalid subscript
    curr--;
    check(curr, "decrement past begin of StrBlobPtr");
    return *this;
}

/* The int parameter is not used, so we do not give it a name. */
StrBlobPtr StrBlobPtr::operator++(int) {
    // no check needed here; the call to prefix increment will do the check
    StrBlobPtr ret = *this;     // save the current value
    ++*this;        // advance one element; prefix ++ checks the increment
    return ret;     // return the saved state
}

StrBlobPtr StrBlobPtr::operator--(int) {
    // no check needed here; the call to prefix decrement will do the check
    StrBlobPtr ret = *this;     // save the current value
    --*this;        // move backward one element; prefix -- checks the element
    return ret;     // return the saved state
}


shared_ptr<vector<string>> StrBlobPtr::check(size_t sz, const string &msg) const {
    // get the address that's returned by lock() function member
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
    // 14.16.txt
    friend bool operator==(const StrBlob &, const StrBlob &);
    friend bool operator!=(const StrBlob &, const StrBlob &);

    typedef std::vector<std::string>::size_type size_type;
    public:
        // implicitly public
        friend class StrBlobPtr;
        StrBlob();
        StrBlob(std::initializer_list<std::string> il);
        // copy-control member operations
        StrBlob(const StrBlob &rhs);
        StrBlob& operator=(const StrBlob &rhs);

        // 14.26.txt
        string& operator[] (size_t n) { return data->at(n); }
        const string& operator[] (size_t n) const { return data->at(n); }


        size_type size() const { return data->size(); }
        bool empty() const { return data->empty(); }
        // add and remove elements
        void push_back(const std::string &t) & { data->push_back(t); }
        // 13.55
        void push_back(const std::string &t) && { data->push_back(t); }
        
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

// copy-control member
StrBlob::StrBlob(const StrBlob &rhs):
    data(make_shared<std::vector<std::string>>(*rhs.data))
    {}

StrBlob& StrBlob::operator=(const StrBlob &rhs) {
    shared_ptr<vector<string>> newTemp = make_shared<vector<string>>(*rhs.data);
    data = newTemp;
    /* data will automatically erase if its only point to the allocated memory*/

    return *this;
}


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

// 14.16.txt
bool operator==(const StrBlob &lhs, const StrBlob &rhs) {
    /*
    We don't do this:
    
        return (lhs.data == rhs.data);
    
    Because the way the copy-initialize and copy-assignment
    of this class is that they allocated a new memory for the
    object being copied or assigned.
    */

    if (lhs.data->size() == rhs.data->size()) {
        for (vector<string>::size_type n = 0; n < lhs.data->size(); n++)
            if (lhs.data->at(n) != rhs.data->at(n))
               return false;
    }
    return true;
}
// 14.16.txt
bool operator!=(const StrBlob &lhs, const StrBlob &rhs) {
    return !(lhs == rhs);
}