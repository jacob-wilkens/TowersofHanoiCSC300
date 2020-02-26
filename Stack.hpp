#include "Node.hpp"

class Stack
{
    private:
        Node* top;
        int count;

    public:
        Stack();
        void push(int payload);
        int pop();
        int peek();
        void display();
        void sort();
        Node* runToIndex(int index);
        bool isEmpty();

};
