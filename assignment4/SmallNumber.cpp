#include <iostream>
#include "SmallNumber.h"

using namespace std;

const bool DEBUG = false;

// Simple implementation of Number interface
SmallNumber::SmallNumber() {
    if (DEBUG) cout << "SmallNumber()" << endl;
    number = 0;
}

SmallNumber::SmallNumber(string s) {
    if (DEBUG) cout << "SmallNumber(string s)" << endl;
    stringstream ss;
    ss << s;
    ss >> number;
    if (number < 0) number = -number; // make non-negative
}

SmallNumber::~SmallNumber() {
    if (DEBUG) cout << "~SmallNumber()" << endl;
}

Number *SmallNumber::factoryMethod(string s) {
    if (DEBUG) cout << "factoryMethod()" << endl;
    return new SmallNumber(s);
}

bool SmallNumber::operator==(const Number *n) {
    if (DEBUG) cout << "equality operator" << endl;
    int num = static_cast<const SmallNumber *>(n)->number; // cast required to access "number"
    return this->number == num;
}

void SmallNumber::operator++(int) {
    if (DEBUG) cout << "increment operator" << endl;
    this->number++;
}

Number *SmallNumber::operator+(const Number *n) {
    if (DEBUG) cout << "addition operator" << endl;
    SmallNumber *result = new SmallNumber();
    int num = static_cast<const SmallNumber *>(n)->number; // cast required to access "number"
    result->number = this->number + num;
    return result;
}

Number *SmallNumber::operator*(const Number *n) {
    if (DEBUG) cout << "multiply operator" << endl;
    SmallNumber *result = new SmallNumber();
    int num = static_cast<const SmallNumber *>(n)->number; // cast required to access "number"
    result->number = this->number * num;
    return result;
}

void SmallNumber::print(std::ostream &os) const {
    os << number;
}