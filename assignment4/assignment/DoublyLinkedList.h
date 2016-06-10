//
// -- TAIL <--> ITEM <--> HEAD --
//

#ifndef ASSIGNMENT4_DOUBLYLINKEDLIST_H
#define ASSIGNMENT4_DOUBLYLINKEDLIST_H

#include <string>

typedef struct LinkedItem {
    int carry;
    LinkedItem *prev;
    LinkedItem *next;
} LinkedItem;

class DoublyLinkedList {
public:
    DoublyLinkedList();

    ~DoublyLinkedList();

    bool isEmpty();

    void insertTail(int value);

    void insertHead(int value);

    LinkedItem *getHead() const;

    LinkedItem *getTail() const;

    LinkedItem *getNextItem(LinkedItem *linkedItem) const;

    LinkedItem *getPrevItem(LinkedItem *linkedItem) const;

    int size();

private:
    LinkedItem *head;
    LinkedItem *tail;
};


#endif //ASSIGNMENT4_DOUBLYLINKEDLIST_H
