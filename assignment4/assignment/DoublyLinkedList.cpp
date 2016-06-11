//
// Yorick de Boer (10786015)
//

#include <cstdlib>
#include <iostream>
#include "DoublyLinkedList.h"

using namespace std;

DoublyLinkedList::DoublyLinkedList() {
    head = NULL;
    tail = NULL;
}

DoublyLinkedList::~DoublyLinkedList() {
//    delete head;
//    delete tail;
}

bool DoublyLinkedList::isEmpty() {
    return (head == NULL);
}

int DoublyLinkedList::size() {
    if (isEmpty()) {
        return 0;
    } else {
        LinkedItem *item = this->getHead();
        int count = 0;
        while (item != NULL) {
            count++;
            item = this->getPrevItem(item);
        }
        return count;
    }
}

void DoublyLinkedList::insertTail(int value) {
    LinkedItem *linkedItem = new LinkedItem();
    linkedItem->carry = value;

    if (isEmpty()) {
        head = linkedItem;
        tail = linkedItem;
        linkedItem->prev = NULL;
        linkedItem->next = NULL;
    } else {
        tail->prev = linkedItem;
        linkedItem->next = tail;
        linkedItem->prev = NULL;
        tail = linkedItem;
    }
}

void DoublyLinkedList::insertHead(int value) {
    LinkedItem *linkedItem = new LinkedItem();
    linkedItem->carry = value;

    if (isEmpty()) {
        head = linkedItem;
        tail = linkedItem;
        linkedItem->prev = NULL;
        linkedItem->next = NULL;
    } else {
        head->next = linkedItem;
        linkedItem->prev = head;
        linkedItem->next = NULL;
        head = linkedItem;
    }
}

LinkedItem *DoublyLinkedList::getHead() const {
    return head;
}

LinkedItem *DoublyLinkedList::getTail() const {
    return tail;
}

LinkedItem *DoublyLinkedList::getNextItem(LinkedItem *linkedItem) const {
    return linkedItem->next;
}

LinkedItem *DoublyLinkedList::getPrevItem(LinkedItem *linkedItem) const {
    return linkedItem->prev;
}






