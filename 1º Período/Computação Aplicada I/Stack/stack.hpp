#ifndef __STACK_HPP__
#define __STACK_HPP__

class Node {
    public:
        int data;
        Node* next;
};

class Stack {
    private:
        Node* top_;
        
        int size_;
        
    public:
        Stack();
        Stack(int size);
        int size();
        void push(int value);
        int top();        
        bool isEmpty();
        void pop();

        ~Stack();
};

#endif