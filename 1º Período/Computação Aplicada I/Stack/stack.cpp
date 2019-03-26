#include "stack.hpp"

#include <cstdlib>
#include <iostream>

Stack::Stack() { top_ = NULL; }

Stack::Stack(int size) { 
    top_ = new Node[size];
}

int Stack::size() {
    return 1;
}

void Stack::push(int value) {
    Node* temp = new Node;
    temp->data = value;
    temp->next = top_;
    top_ = temp;
    size_++;
}

int Stack::top() {
    return top_->data;
}

bool Stack::isEmpty() {
    return top_ == NULL;
}

void Stack::pop() {
    if(!isEmpty()) {
        Node* temp = top_;
        top_ = temp->next;
        delete temp;
        size_--;
    }else {
        std::cout << "Stack is empty!\n" ;
    }
}

Stack::~Stack() {
    while(!isEmpty()) {
        Node* temp = top_;
        top_ = temp->next;
        delete temp;
    }
    std::cout << "Destructor called" << std::endl;
}