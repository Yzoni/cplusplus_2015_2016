//
// Created by yorick on 27-4-16.
//

#ifndef CMETHODEN_LARGENUMBER_H
#define CMETHODEN_LARGENUMBER_H


#include "Number.h"

class LargeNumber : Number {

public:
    LargeNumber(const string &s) : Number(s) { }

    LargeNumber() : Number() { }

private:
    virtual Number *factoryMethod(string s);

    virtual bool operator==(const Number *n);

    virtual void operator++(int i);

    virtual Number *operator+(const Number *n);

    virtual Number *operator*(const Number *n);

    virtual void print(std::ostream &os) const;
};


#endif //CMETHODEN_LARGENUMBER_H
