#ifndef CMETHODEN_NUMBER_H
#define CMETHODEN_NUMBER_H

#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;


// interface for Number type
// its methods are virtual so they can be redefined in derived class
class Number {
public:

    Number() { };

    Number(string s) { }; // constructor based in string representation of number
    virtual ~Number() { }; // makes destructor virtual
    virtual Number *factoryMethod(string s) = 0; // returns new Number object

    virtual bool operator==(const Number *n) = 0; // test for equality
    virtual bool operator!=(const Number *n)    // test for inequality
    { return !((*this) == n); }

    virtual void operator++(int) = 0; // increment number
    virtual Number *operator+(const Number *n) = 0; // returns new Number object after addition
    virtual Number *operator*(const Number *n) = 0; // returns new Number object after multiplication

    friend std::ostream &operator<<(std::ostream &os, const Number *n);

protected:

    virtual void print(std::ostream &os) const = 0; // prints the number

};

#endif //CMETHODEN_NUMBER_H
