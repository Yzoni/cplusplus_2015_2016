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

    bool carryOver = false;
    bool addExtra = false;

    currentItem->carry += 1;
    while (currentItem != NULL) {
        if (carryOver) {
            currentItem->carry++;
            carryOver = false;
            continue;
        }
        if (digitOverflow(currentItem->carry)) {
            currentItem->carry -= pow(10, k);
            carryOver = true;
            if (currentItem->prev == NULL) {
                addExtra = true;
            }
        }
        currentItem = num.getPrevItem(currentItem);
    }
    if (addExtra) {
        num.insertTail(1);
    }

//    int integer;
//    int betweenResult;
//    bool carryOver = false;
//    bool addExtra = false;
//
//    istringstream(currentItem->carry) >> integer;
//    betweenResult = integer + 1;
//
//    char str[15];
//    sprintf(str, "%d", betweenResult);
//    currentItem->carry = str;
//
//    if (betweenResult >= pow(10, k + 1)) {
//        carryOver = true;
//        betweenResult = betweenResult - pow(10, k + 1);
//
//        if (betweenResult == 0) {
//            stringstream ss;
//            for (int i = 0; i <= k; ++i) {
//                ss << "0";
//            }
//            currentItem->carry = ss.str();
//            ss.str("");
//        } else {
//            sprintf(str, "%d", betweenResult);
//            currentItem->carry = str;
//        }
//    }
//    currentItem = num.getPrevItem(currentItem);
//    while (currentItem != NULL) {
//        if (carryOver) {
//            carryOver = false;
//            istringstream(currentItem->carry) >> integer;
//            betweenResult = integer + 1;
//
//            sprintf(str, "%d", betweenResult);
//            currentItem->carry = str;
//
//            if (currentItem->prev == NULL) {
//                addExtra = true;
//            }
//
//            if (betweenResult >= pow(10, k + 1)) {
//                carryOver = true;
//                betweenResult = betweenResult - pow(10, k + 1);
//
//                if (betweenResult == 0) {
//                    stringstream ss;
//                    for (int i = 0; i <= k; ++i) {
//                        ss << "0";
//                    }
//                    currentItem->carry = ss.str();
//                    ss.str("");
//                } else {
//                    sprintf(str, "%d", betweenResult);
//                    currentItem->carry = str;
//                }
//            }
//        }
//        currentItem = num.getPrevItem(currentItem);
//    }
//    if (addExtra) {
//        num.insertTail("1");
//    }
}

Number *LargeNumber::operator+(const Number *n) {
    DoublyLinkedList num_left = static_cast<const LargeNumber *>(n)->doublyLinkedList; // cast required to access "number"
    DoublyLinkedList num_right = this->doublyLinkedList;

    DoublyLinkedList *result = new DoublyLinkedList();

//    LinkedItem *currentItemLeft = num_left.getHead();
//    LinkedItem *currentItemRight = num_right.getHead();
//
//
//    int integerL;
//    int integerR;
//    int betweenResult;
//
//    bool carryOver = false;
//    while (currentItemLeft != NULL && currentItemRight != NULL) {
//        istringstream(currentItemLeft->carry) >> integerL;
//        istringstream(currentItemRight->carry) >> integerR;
//
//        betweenResult = integerL + integerR;
//        if (carryOver) {
//            betweenResult++;
//        }
//
//        if (digitOverflow(betweenResult)) {
//            betweenResult = 0;
//            carryOver = true;
//        }
//
////        result->insertHead(betweenResult);
//
//        currentItemLeft = num_left.getPrevItem(currentItemLeft);
//        currentItemRight = num_right.getPrevItem(currentItemRight);
//    }
//
//    LargeNumber *largeNumber = new LargeNumber();
//    largeNumber->doublyLinkedList = *result;
//
//    return largeNumber;
}

Number *LargeNumber::operator*(const Number *n) {
    return NULL;
}

void LargeNumber::print(std::ostream &os) const {
    LinkedItem *currentItem = doublyLinkedList.getTail();

    while (currentItem != NULL) {
        os << currentItem->carry << std::setfill('0') << std::setw(k);
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


