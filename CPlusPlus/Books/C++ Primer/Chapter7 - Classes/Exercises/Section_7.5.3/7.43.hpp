#ifndef NODEFAULT_HPP
#define NODEFAULT_HPP

class NoDefault {
    public:
        NoDefault(int i): data_member(i) { }
        int getData(void) const {
            return data_member;
        }
    private:
        int data_member;
};

class Cclass {
    public:
        Cclass(): Cclass(0) { }           // delegating the constructor of C(int)
        Cclass(int i): nd(i) { }

        NoDefault &getObj(void) {
            return nd;
        }
    private:
        NoDefault nd;

};

#endif