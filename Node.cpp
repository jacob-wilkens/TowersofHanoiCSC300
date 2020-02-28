#include "Node.hpp"

Node::Node(int payload)
{
    this->payload = payload;
    this->nextNode = 0;
}

int Node::getPayload()
{
    return this->payload;
}

void Node::setNextNode(Node* n)
{
    this->nextNode = n;
}

Node* Node::getNextNode()
{
    return this->nextNode;
}