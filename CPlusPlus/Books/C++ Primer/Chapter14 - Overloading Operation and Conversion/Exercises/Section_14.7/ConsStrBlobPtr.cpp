#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class StrBlob;

class ConstStrBlobPtr {
    
    public:

        ConstStrBlobPtr(): curr(0) { }
        ConstStrBlobPtr(const StrBlob &strBlob, size_t sz = 0):
            pointToVec(strBlob.data), curr(sz) { }

        const string& deref() const;
        const ConstStrBlobPtr& incr();      // prefix version

        // 14.30.txt
        const string& operator*() const;
        const string* operator->() const;


    private:
        shared_ptr<const vector<string>> check(size_t n, const string &msg) const {
            shared_ptr<const vector<string>> ret = pointToVec.lock();     // is the vector is exist
            if (!ret)
                throw runtime_error("Unbound ConsStrBlobPtr");
            else if (curr > ret->size())
                throw out_of_range(msg);

            return ret; 
        }

        weak_ptr<const vector<string>> pointToVec;
        size_t curr;
};

const string& ConstStrBlobPtr::deref() const {
    shared_ptr<const vector<string>> getAddr = check(curr, "dereference past the end");

    return (*getAddr)[curr];
}

const ConstStrBlobPtr& ConstStrBlobPtr::incr() {
    // if curr already points past the end of container, can't increment it
    check(curr, "increment past the end of ConstStrBlobPtr");
    ++curr;     // advance the current state;
    return *this;
}

const string& ConstStrBlobPtr::operator*() const {
    return deref();
}

const string* ConstStrBlobPtr::operator->() const {
    return &deref();
}

class StrBlob {
    typedef std::vector<std::string>::size_type size_type;
    friend class ConstStrBlobPtr;
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

        ConstStrBlobPtr cbegin() { return ConstStrBlobPtr(*this); }
        ConstStrBlobPtr cend() { return ConstStrBlobPtr(*this, data->size()); }

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

ConstStrBlobPtr::ConstStrBlobPtr(const StrBlob &strBlob, size_t sz):
    pointToVec(strBlob.data), curr(sz) { }


int main(void) {
    const StrBlob s1 {"Hello","There"};
    ConstStrBlobPtr p(s1);

    cout << *p << endl;
    return 0;
}