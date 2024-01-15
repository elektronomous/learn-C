#include <iostream>
#include <string>
#include <memory>

using namespace std;

/* simplified implementation of the memory allocation strategy for a vector-like class */
class StrVec { 
    // 14.16.txt
    friend bool operator==(const StrVec &, const StrVec &);
    friend bool operator!=(const StrVec &, const StrVec &);
    // 14.18.txt
    friend bool operator<(const StrVec &, const StrVec &);
    
    public:
        StrVec():       // the allocator member is default initialized
            elements(nullptr), first_free(nullptr), cap(nullptr) {}
        
        // 13.40.cpp
        StrVec(const initializer_list<string> &il);
        
        StrVec(const StrVec &);             // copy constructor
        StrVec& operator=(const StrVec &);  // copy assignment
        ~StrVec();                          // destructor

        // 13.6.2
        // 13.49.txt
        StrVec(StrVec &&s) noexcept;            // move constructor
        StrVec& operator=(StrVec&&) noexcept;   // move-assigment
        // 14.4 Assignment Operator
        StrVec& operator=(const std::initializer_list<string> &);
        // 14.5 Subscript operator
        std::string& operator[] (std::size_t n) { 
            return elements[n]; 
        }
        const std::string& operator[] (std::size_t n) const { 
            return elements[n]; 
        }


        // copy the element
        void push_back(const string &s);
        // know the size
        string::size_type size(void) const { return first_free - elements; }
        // know the capacity
        string::size_type capacity(void) const { return cap - elements; }

        // create begin and end
        string* begin(void) const { return elements; }
        string* end(void) const { return first_free; }
    private:
        // method members
        allocator<string> alloc;            // allocates the element

        // used by the function that add elements to the StrVec
        void chk_n_alloc(void) {
            if (size() == capacity()) reallocate();
        }

        // utilities used by copy constructor, assignment operator, and destructor
        pair<string*, string*> alloc_n_copy(const string*, const string*);
        void free(void);            // destroy the elements and free the space
        void reallocate(void);      // get more space and copy the existing elements

        // data members
        string *elements;       // pointer to the first element in the array
        string *first_free;     // pointer to the first free element in the array
        string *cap;            // pointer to one past the last element in the array
};

void StrVec::push_back(const string &s) {
    chk_n_alloc();      // ensure that there is room for another elements
    // construct a copy of s in the element to which first_free points
    alloc.construct(first_free++, s);
}

pair<string*, string*> StrVec::alloc_n_copy(const string *b, const string *e) {
    // allocate space to hold as many elements as are in the range
    string *data = alloc.allocate(e - b);
    // initialize and return a pair constructed from data and
    // the value returned by uninitialized_copy
    return {data, uninitialized_copy(b,e,data)};
}

StrVec::StrVec(const initializer_list<string> &sl) {
    pair<string*, string*> newData = alloc_n_copy(sl.begin(), sl.end());
    elements = newData.first;
    first_free = cap = newData.second;
}

void StrVec::free(void) {
    // may not pass deallocate a 0 pointer; if elements is 0, there's no work to do
    if (elements) {
        // destroy the old elements in the reverse order
        for (string *last = first_free; last != elements; /* empty */)
            alloc.destroy(--last);
        alloc.deallocate(elements, cap-elements);
        
    }
}

StrVec::StrVec(const StrVec &rhs) {
    pair<string*, string*> newData = alloc_n_copy(rhs.begin(), rhs.end());
    elements = newData.first;
    first_free = cap = newData.second;
}

StrVec::~StrVec(void) {
    free();
}

StrVec& StrVec::operator=(const StrVec &rhs) {
    // call alloc_n_copy to allocate exactly as many elements as in rhs
    pair<string*, string*> newData = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    elements = newData.first;
    first_free = cap = newData.second;

    return *this;
}

// 14.4 Assignment Operators
StrVec& StrVec::operator=(const initializer_list<string> &il) {
    // allocate space and copies elements from given range
    pair<string*, string*> newData = alloc_n_copy(il.begin(), il.end());
    // destroy the elements in this object and free the space
    free();
    elements = newData.first;   // update data members to point to new space
    first_free = cap = newData.second;

    return *this;
}

void StrVec::reallocate(void) {
    // we'll allocate space for twice as many elements as the current size
    string::size_type newCapacity = size() ? size() * 2 : 1;   /* If the StrVec is empty, we allocate room for one element: */

    // allocate new memory
    string* newData = alloc.allocate(newCapacity);

    // move the data from the old memory to the new
    string *dest = newData;     // points to the next free position in the new array
    string *elem = elements;    // points to the next element in the old array
    /* for (string::size_type i = 0; i != size(); i++)
        alloc.construct(dest++, std::move(*elem++));
    
       There is an alternative way, on which we could use move iterator noted in NOTE4.txt
       13.6.2 Move Constructor:
    */
    uninitialized_copy(make_move_iterator(begin()), make_move_iterator(end()), dest);

    free();     // free the old space once we've moved the elements
    // update our data structure to point to the new elements
    elements = newData;
    first_free = dest;
    cap = elements + newCapacity;
}

// 13.49.txt
StrVec::StrVec(StrVec &&s) noexcept :    // move won't throw any exceptions
    // member initializers are take over the resource in s
    elements(s.elements), first_free(s.first_free), cap(s.cap) {

    // leave s in a state in which it is safe to run the destructor
    s.elements = s.first_free = s.cap = nullptr;
}

// 13.49.txt
StrVec& StrVec::operator=(StrVec &&rhs) noexcept {
    // direct test for self-assignment
    if (this != &rhs) {
        free();                     // free existing elements
        elements = rhs.elements;    // take over resources from rhs
        first_free = rhs.first_free;
        cap = rhs.cap;

        // leave the rhs in a destructible state
        rhs.elements = rhs.first_free = rhs.cap = nullptr;
    }

    return *this;
}

// 14.16.txt
bool operator==(const StrVec &lhs, const StrVec &rhs) {
    /* 
    return (lhs.elements == rhs.elements &&
        lhs.first_free == rhs.first_free &&
        lhs.cap == rhs.cap);
    
    The way the copy-initialized and copy-assignment do their job
    is act like value which is when you initialized or assigned an
    object, that object is independent from each other. If you compare
    like the above code, then you obviously always get different object.

    */
    if (lhs.size() == rhs.size()) {
        for (string::size_type n = 0; n < lhs.size(); n++)
            if (lhs.elements[n] != rhs.elements[n])
                return false;
    }
    return true;
}

// 14.16.txt
bool operator!=(const StrVec &lhs, const StrVec &rhs) {
    return !(lhs == rhs);
}

// 14.18.txt
bool operator<(const StrVec &lhs, const StrVec &rhs) {
    if (lhs.size() < rhs.size()) return true;
    else if (rhs.size() == lhs.size()) {
        for (string::size_type n = 0; n < lhs.size(); n++)
            if (lhs.elements[n] > rhs.elements[n])
                return false;
            return true;
    }

    return false;
}