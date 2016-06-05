//
// Yorick de Boer (10786015)
//

#ifndef CMETHODEN_LARGENUMBER_H
#define CMETHODEN_LARGENUMBER_H


#include "Number.h"
#include "DoublyLinkedList.h"

class LargeNumber : public Number {

public:
    LargeNumber();

    LargeNumber(string s);

    ~LargeNumber();

    Number *factoryMethod(string s);

    bool operator==(const Number *n);

    void operator++(int);

    Number *operator+(const Number *n);

    Number *operator*(const Number *n);

    void printArray();


protected:
    void print(std::ostream &os) const;

private:
    DoublyLinkedList doublyLinkedList;

    bool digitOverflow(int d1);

};

#endif //CMETHODEN_LARGENUMBER_H
