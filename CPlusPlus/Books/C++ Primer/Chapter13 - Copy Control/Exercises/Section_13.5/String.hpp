#include <iostream>
#include <memory>
#include <utility>

using namespace std;
class String {
    friend ostream& print(ostream &, const String &);
    public:
        String():
            elements(alloc.allocate(1)), str(elements), cap(elements) {
                alloc.construct(str++, '\0');
                cap = str;
            }
        
        String(const char s[]);

        // copy control members
        String(const String &rhs);
        String& operator=(const String &rhs);
        ~String() { free(); }
        
        void insert(const char c);
        void push_back(const char c);
        size_t find(const char &c);
    
        size_t size() const { return str - elements; }
        size_t capacity() const { return cap - elements; }

        char *begin() const { return elements; }
        char *end() const { return str; }
    private:
        pair<char*,char*> alloc_n_copy(const char *begin, const char *end);
        void chk_n_alloc(void) {
            if (size() == capacity()) reallocate();
        }
        void reallocate(void);
        void free(void);

        allocator<char> alloc;
        char *elements;
        char *str;
        char *cap;
};

void String::push_back(const char c) {
    insert(c);
}

void String::insert(const char c) {
    // you first check the allocated address, if it's not enough
    chk_n_alloc();

    alloc.construct(str, c);
}

size_t String::find(const char &c) {
    char *start;
    for (start = elements; start != str; start++)
        if (*start == c) break;
    
    return start == str ? string::npos : start - elements;
}

void String::reallocate(void) {
    // if you got no elements, then if you just push_back/insert a char
    // then you'll get a 1 size
    size_t newCapacity = size() ? size() * 2 : 1;

    // new memory
    char *newData = alloc.allocate(newCapacity);

    // destination new memory
    char *newDestination = newData;
    // old memory
    char *oldData = elements;
    // move the old to the new 
    for (char *start = elements; start != str; )
        alloc.construct(newDestination++, std::move(*oldData++));
    
    // reposition our pointer
    elements = newData;
    str = newDestination;
    cap = elements + newCapacity;
}

pair<char*, char*> String::alloc_n_copy(const char *a, const char *b) {
    // allocate new memory first
    char* newData = alloc.allocate(b - a);

    return {newData, uninitialized_copy(a,b,newData)};
}

void String::free(void) {
    if (elements) {
        for (char *start = str; start != elements; /* empty */)
            alloc.destroy(--start);
        alloc.deallocate(elements, str - elements);
    }
}

String::String(const String &rhs) {
    pair<char*,char*> allocNewData = alloc_n_copy(rhs.begin(), rhs.end());

    elements = allocNewData.first;
    str = cap = allocNewData.second;
}

String& String::operator=(const String &rhs) {
    pair<char*, char*> newData = alloc_n_copy(rhs.begin(), rhs.end());
    // free this object before we go to the newData
    free();

    elements = newData.first;
    str = cap = newData.second;

    return *this;
}

String::String(const char c[]) {
    // count the capacity
    const char *start = c;
    for (;*start != '\0'; start++)
        ;
    
    size_t newCapacity = start - c;
    char *newData = alloc.allocate(newCapacity);

    // new memory
    char *newDest = newData;

    const char *track = c;
    for (size_t i = 0; i < newCapacity; i++)
        alloc.construct(newDest++, *track++);
    
    elements = newData;
    str = cap = newDest;
}

ostream& print(ostream &os, const String &s) {
    for (const char *start = s.elements; start != s.str; start++)
        os << *start;
    return os;
}