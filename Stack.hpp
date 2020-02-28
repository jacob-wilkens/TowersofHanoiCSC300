#include "Node.hpp"

class Stack
{
    private:
        Node* top;

    public:
        Stack();
        void push(int payload);
        int pop();
        int peek();
        void display();
};