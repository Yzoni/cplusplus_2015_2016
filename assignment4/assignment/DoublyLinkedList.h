//
// Created by yorick on 14-5-16.
//

#ifndef ASSIGNMENT4_DOUBLYLINKEDLIST_H
#define ASSIGNMENT4_DOUBLYLINKEDLIST_H

#include <string>

typedef struct LinkedItem {
    std::string carry;
    LinkedItem *prev;
    LinkedItem *next;
} LinkedItem;

class DoublyLinkedList {
public:
    DoublyLinkedList();

    ~DoublyLinkedList();

    bool isEmpty();

    void insertTail(std::string value);

    void insertHead(std::string value);

    LinkedItem *getHead() const;

    LinkedItem *getTail() const;

    LinkedItem *getNextItem(LinkedItem *linkedItem) const;

    LinkedItem *getPrevItem(LinkedItem *linkedItem) const;

private:
    LinkedItem *head;
    LinkedItem *tail;

};


#endif //ASSIGNMENT4_DOUBLYLINKEDLIST_H
