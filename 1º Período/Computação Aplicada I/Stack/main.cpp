#include <iostream>
#include "stack.hpp"

using namespace std;

int main() {
    Stack s1(10);
    // Stack s2;

    s1.push(1);
    s1.push(2);
    s1.push(3);
    // s1.push(4);
    // s1.push(5);
    // s1.push(6);
    // s1.push(10);
    // s1.push(20);
    // s1.push(30);
    s1.push(40);



    s1.pop();
    s1.pop();

    s1.display();

    // cout << endl;
    
    // s2.push(1);
    // s2.pop();
    // s2.push(2);
    // s2.push(3);
    // s2.pop();
    // s2.push(4);
    // s2.push(5);
    // s2.pop();
    // s2.push(6);
    // s2.display();

    
    return 0;
}
