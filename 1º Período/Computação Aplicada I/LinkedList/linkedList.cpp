#include "linkedList.hpp"
#include <cstdlib>

LinkedList::LinkedList() { list_ = NULL; }

void LinkedList::push_front(int value) {
    Node* temp;
    temp->data = value;
    temp->next = NULL;
    temp->prev = list_->prev;
    list_->next = temp;

    delete temp;
}

void LinkedList::pop_front() {
    Node* temp;
    temp->data = temp->prev->data;
    temp->next = NULL;
    temp->prev = list_;
    list_->next = temp;

    delete temp;
}

LinkedList::~LinkedList() {
    delete list_;
}