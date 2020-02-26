#include "Stack.hpp"
#include <iostream>

Stack::Stack()
{
    this->top = 0;
    this->count = 0;
}

void Stack::push(int payload)
{
    Node* n = new Node(payload);
    if(top)
    {
        //we have at least one element on our stack
        n->setNextNode(this->top);
        this->top = n;
    }
    else
    {
        this->top = n;
    }
    this->count++;
}

int Stack::pop()
{
    int valueToReturn = this->top->getPayload();
    Node* temp = this->top;
    top = top->getNextNode();
    temp->setNextNode(0);
    delete temp;
    this->count--;
    return valueToReturn;
}

int Stack::peek()
{
    return this->top->getPayload();
}

void Stack::display()
{
    if(this->top)
    {
        Node* currNode = this->top;
        while(currNode)
        {
            std::cout << currNode->getPayload() << "\n";
            currNode = currNode->getNextNode();
        }
    }
    else
    {
        std::cout << "Empty Stack\n";
    }
}
void Stack::sort(){
    if(this->count > 1)
    {
        int currFollowerPos;
        Node* theFollower;
        Node* temp; //used for swapping as well as an extra little thing

        for(int currPos = 1; currPos < this->count; currPos++)
        {
            currFollowerPos = currPos;
            theFollower = this->runToIndex(currPos);
            
            //only do stuff if I am not at the front of the list
            while(currFollowerPos > 0)
            {
                //get the guy before me
                temp = this->runToIndex(currFollowerPos-1);

                //should we swap?
                if(theFollower->getPayload() < temp->getPayload())
                {
                    temp->setNextNode(theFollower->getNextNode());
                    theFollower->setNextNode(temp);
                    if(currFollowerPos == 1) //the guy before me was the head of the list
                    {
                        //the guy before me WAS the head of the list, so update head
                        this->top = theFollower;
                    }
                    else
                    {
                        //the guy before me is not the head of the list, so update his nextNode
                        temp = this->runToIndex(currFollowerPos - 2);
                        temp->setNextNode(theFollower);
                    }
                    currFollowerPos--;
                    
                }
                else
                {
                    //I am done swapping THIS TIME!!!!! heheheh lol stacy
                    //move to the next start pos
                    break; //take me to the line following this while loop  
                }
            } //end of while
            //this is where I go after break
        } //end of my for loop
        //list is now sorted
    }
}

Node* Stack::runToIndex(int index){
        Node* currNode = this->top;
    for(int i = 0; i < index; i++)
    {
        currNode = currNode->getNextNode();
    }
    return currNode;
}
bool Stack::isEmpty(){
    if(this->top == 0){
        return true;
    } else{
        return false;
    }
}