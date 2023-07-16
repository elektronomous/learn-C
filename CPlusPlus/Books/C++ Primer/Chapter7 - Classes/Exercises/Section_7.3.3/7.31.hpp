#ifndef 7_33_HPP
#define 7_33_HPP

class X, Y;

class X {
    private:
        Y* y;
};

class Y {
    private:
        X* x;
};

#endif