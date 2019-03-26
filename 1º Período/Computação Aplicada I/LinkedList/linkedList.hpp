class Node {
    public:
        int data;
        Node* next;
        Node* prev;
};

class LinkedList {
    private:
        Node* front_;
    
    public:
        LinkedList();
        int front();
        int back();
        void push_front(int value);
        void push_back(int value);
        void pop_front();
        void pop_back();
        ~LinkedList();
};