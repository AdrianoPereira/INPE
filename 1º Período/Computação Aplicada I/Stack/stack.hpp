#ifndef __STACK_HPP__
#define __STACK_HPP__

class Stack {
    private:
        int* arr_;
        int maxsize_, indextop_;
        
    public:
        Stack();    
        Stack(int size);

        void push(int value);
        void pop(); 
        int top();
        bool isEmpty();
        bool isFull();
        int size();        
        void display();
        
        ~Stack();
};

#endif