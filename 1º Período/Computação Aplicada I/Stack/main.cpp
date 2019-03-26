#include <iostream>
#include "stack.hpp"

using namespace std;

int main() {
    Stack stack1(42);
    
    stack1.push(1);
    stack1.push(2);
    stack1.push(3);
    stack1.push(4);
    stack1.push(5);

    while(!stack1.isEmpty()) {
        cout << stack1.top() << endl;
        stack1.pop();        
    }


    cout << "Run finish" << endl;


    
    return 0;
}
