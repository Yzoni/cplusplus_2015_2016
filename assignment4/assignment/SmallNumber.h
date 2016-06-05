//
// Created by yorick on 27-4-16.
//

#ifndef CMETHODEN_SMALLNUMBER_H
#define CMETHODEN_SMALLNUMBER_H

#include "Number.h"

class SmallNumber : public Number {

public:
    SmallNumber();

    SmallNumber(string s);

    ~SmallNumber();

    Number *factoryMethod(string s);

    bool operator==(const Number *n);

    void operator++(int);

    Number *operator+(const Number *n);

    Number *operator*(const Number *n);

protected:
    void print(std::ostream &os) const;

private:
    int number;
};


#endif //CMETHODEN_SMALLNUMBER_H
