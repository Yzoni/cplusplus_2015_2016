//
// Yorick de Boer (10786015)
//
#include <string>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include "LargeNumber.h"

using namespace std;

const bool DEBUG = true;
const int k = 4;

LargeNumber::LargeNumber() {
    if (DEBUG) cout << "LargeNumber()" << endl;
    doublyLinkedList.insertHead(0);
}

LargeNumber::LargeNumber(string s) {
    if (DEBUG) cout << "LargeNumber(string s)" << endl;

    ostringstream os;
    string theString;

    int integer;

    // Iterate over string and split it in parts of length k
    std::string::reverse_iterator it;
    int count = 1;
    for (it = s.rbegin(); it != s.rend(); ++it) {
        os << *it;
        if (count >= k) {
            theString = os.str();
            reverse(theString.begin(), theString.end());
            istringstream(theString) >> integer;
            doublyLinkedList.insertTail(integer);

            os.str(""); // Clear the stream
            count = 0;
        }
        count = count + 1;
    }

    // Check if stream is empty, if not add last part
    if (os.str().empty() == 0) {
        theString = os.str();
        reverse(theString.begin(), theString.end());
        istringstream(theString) >> integer;
        doublyLinkedList.insertTail(integer);
    }
}

LargeNumber::~LargeNumber() {
    if (DEBUG) cout << "~LargeNumber()" << endl;
}

Number *LargeNumber::factoryMethod(string s) {
    if (DEBUG) cout << "factoryMethod()" << endl;
    return new LargeNumber(s);
}

bool LargeNumber::operator==(const Number *n) {
    DoublyLinkedList num_left = static_cast<const LargeNumber *>(n)->doublyLinkedList; // cast required to access "number"
    DoublyLinkedList num_right = this->doublyLinkedList;

    LinkedItem *currentItemLeft = num_left.getHead();
    LinkedItem *currentItemRight = num_right.getHead();
    while (currentItemLeft != NULL || currentItemRight != NULL) {
        if (currentItemLeft->carry != currentItemRight->carry) {
            return false;
        }

        currentItemLeft = num_left.getPrevItem(currentItemLeft);
        currentItemRight = num_right.getPrevItem(currentItemRight);
    }
    return true;
}

void LargeNumber::operator++(int) {
    DoublyLinkedList &num = this->doublyLinkedList;
    LinkedItem *currentItem = num.getHead();

    // First ++ is 1
    int carryOver = 1;
    bool addExtra = false;

    while (currentItem != NULL) {
        currentItem->carry += carryOver;

        if (digitOverflow(currentItem->carry)) {
            currentItem->carry -= pow(10, k);
            carryOver = 1;
            // Add the extra one in front if necessary
            if (currentItem->prev == NULL) {
                addExtra = 1;
            }
        } else {
            carryOver = 0;
        }
        currentItem = num.getPrevItem(currentItem);
    }

    if (addExtra) {
        num.insertTail(1);
    }
}

/*
 * TOP
 * BOTTOM +
 * --------
 * RESULT
 */
Number *LargeNumber::operator+(const Number *n) {
    DoublyLinkedList numTop = static_cast<const LargeNumber *>(n)->doublyLinkedList; // cast required to access "number"
    DoublyLinkedList numBottom = this->doublyLinkedList;

    DoublyLinkedList *result = new DoublyLinkedList();

    // Check if bottom is largest number, if not swap pointers
    if (numTop.size() > numBottom.size()) {
        swap(numTop, numBottom);
    }

    // Copy the bottom values to result
    LinkedItem *currentBottom = numBottom.getHead();
    while (currentBottom != NULL) {
        result->insertTail(currentBottom->carry);
        currentBottom = numBottom.getPrevItem(currentBottom);
    }

    // Plus with the bottom value
    LinkedItem *currentTop = numBottom.getHead();
    LinkedItem *currentResult = result->getHead();

    int carryOver = 0;
    bool addExtra = false;
    int currentTopCarry;
    while (currentResult != NULL) {

        // If top number reached end
        if (currentTop == NULL) {
            currentTopCarry = 0;
        } else {
            currentTopCarry = currentTop->carry;
        }
        currentResult->carry += currentTopCarry + carryOver;

        if (digitOverflow(currentResult->carry)) {
            currentResult->carry -= pow(10, k);
            carryOver = 1;
            // Add the extra one in front if necessary
            if (currentResult->prev == NULL) {
                addExtra = 1;
            }
        } else {
            carryOver = 0;
        }

        // If bottom number reached end
        if (currentTop != NULL) {
            currentTop = numTop.getPrevItem(currentTop);
        }
        currentResult = result->getPrevItem(currentResult);
    }

    if (addExtra) {
        result->insertTail(1);
    }

    LargeNumber *largeNumber = new LargeNumber();
    largeNumber->doublyLinkedList = *result;

    return largeNumber;
}

/*
 * TOP
 * BOTTOM *
 * --------
 * RESULT
 */
Number *LargeNumber::operator*(const Number *n) {
    DoublyLinkedList numTop = static_cast<const LargeNumber *>(n)->doublyLinkedList; // cast required to access "number"
    DoublyLinkedList numBottom = this->doublyLinkedList;

    DoublyLinkedList *result = new DoublyLinkedList();

    // Check if bottom is largest number
    if (numTop.size() > numBottom.size()) {
        swap(numTop, numBottom);
    }

    // Plus with the bottom value
    LinkedItem *currentBottom = numBottom.getHead();

    int carryOver = 0;
    bool addExtra = false;
    int currentTopCarry;
    while (currentBottom != NULL) {

        LinkedItem *currentTop = numTop.getHead();
        int count = 0;
        LargeNumber *betweenResult = new LargeNumber();
        while (currentTop != NULL) {
            int zeros = pow(10, (k * count));
            ostringstream convert;   // stream used for the conversion
            convert << (currentTop->carry *
                        zeros);      // insert the textual representation of 'Number' in the characters in the stream
            LargeNumber *betweenResultPart = new LargeNumber(convert.str());
            betweenResult = static_cast<LargeNumber *>((*betweenResult) + betweenResultPart);
            currentTop = numTop.getPrevItem(currentTop);
        }

//        // If bottom number reached end
//        if (currentTop == NULL) {
//            currentTopCarry = 0;
//        } else {
//            currentTopCarry = currentTop->carry;
//        }
//        currentResult->carry += currentTopCarry + carryOver;
//
//        if (digitOverflow(currentResult->carry)) {
//            currentResult->carry -= pow(10, k);
//            carryOver = 1;
//            // Add the extra one in front if necessary
//            if (currentResult->prev == NULL) {
//                addExtra = 1;
//            }
//        } else {
//            carryOver = 0;
//        }
//
//        // If bottom number reached end
//        if (currentTop != NULL) {
//            currentTop = numTop.getPrevItem(currentTop);
//        }
//        currentBottom = result->getPrevItem(currentResult);
    }

    if (addExtra) {
        result->insertTail(1);
    }

    LargeNumber *largeNumber = new LargeNumber();
    largeNumber->doublyLinkedList = *result;

    return largeNumber;
}

void LargeNumber::print(std::ostream &os) const {
    LinkedItem *currentItem = doublyLinkedList.getTail();

    while (currentItem != NULL) {
        os << currentItem->carry << std::setfill('0') << std::setw(k);
//        os << " ";
        currentItem = doublyLinkedList.getNextItem(currentItem);
    }
}

bool LargeNumber::digitOverflow(int d1) {
    unsigned int number_of_digits_d1 = 0;
    do {
        ++number_of_digits_d1;
        d1 /= 10;
    } while (d1);

    return number_of_digits_d1 > k;
}

void LargeNumber::printArray() {
    DoublyLinkedList &num = this->doublyLinkedList;
    LinkedItem *currentItem = num.getTail();

    while (currentItem != NULL) {
        cout << currentItem->carry << " => ";
        currentItem = num.getNextItem(currentItem);
    }
    cout << endl;
}


