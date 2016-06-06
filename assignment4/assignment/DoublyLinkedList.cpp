//
// Created by yorick on 14-5-16.
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






