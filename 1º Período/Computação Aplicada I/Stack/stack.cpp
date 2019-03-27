#include "stack.hpp"
#define SIZE_DEFAULT 5
#define EXTRA 10

#include <cstdlib>
#include <iostream>

Stack::Stack() { 
    arr_ = new int[SIZE_DEFAULT];
    maxsize_ = SIZE_DEFAULT;
    indextop_ = -1;
}

Stack::Stack(int size) { 
    arr_ = new int[size];
    maxsize_ = size;
    indextop_ = -1;
}

void Stack::push(int value) {
   if(isFull()) {
        std::cout << "A pilha atingiu sua capacidade máxima! Alocando mais memória...\n";
        maxsize_ += EXTRA;
        int* aux;
        aux = new int[maxsize_];
        // for(int x=0; x<maxsize_; x++) std::cout << aux[x] << std::endl;
        if(aux == NULL) {
            std::cout << "Memória insuficiente!" << std::endl;
           exit(1);
        }

        for(int x=0; x<=indextop_; x++) 
            aux[x] = arr_[x];
        
        delete[] arr_;
        arr_ = new int[maxsize_];
        arr_ = aux;
        delete[] aux;
   }
   arr_[++indextop_+1] = value;
   std::cout << top() << " adicionado" << std::endl;
}

void Stack::pop() {
    if(!isEmpty()) {
        indextop_--;
    }else {
        std::cout << "A pilha está vazia!\n";
    }
   
}

int Stack::top() {
    return arr_[indextop_];
}

bool Stack::isEmpty() {
    return indextop_ < 0;
}

bool Stack::isFull() {
    return indextop_ >= maxsize_-2;
}
    

int Stack::size() {
    return indextop_+1;
}

void Stack::display() {
   for(int x=indextop_; x>=0; x--) {
       std::cout << arr_[x] << std::endl;
   }
}

Stack::~Stack() {
    delete[] arr_;
}