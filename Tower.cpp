#include "Tower.hpp"
#include <iostream>

Tower::Tower(int towerNumber)
{
    this->top = 0;
    this->count = 0;
    this->towerNumber = towerNumber;
}

int Tower::getCount()
{
    return this->count;
}
        
void Tower::push(Disk* d)
{
    if(this->top)
    {
        d->setNextDisk(this->top);    
    }  
    this->top = d;
    this->count++;
}

Disk* Tower::pop()
{
    if(this->top)
    {
        Disk* diskToReturn = this->top;
        this->top = this->top->getNextDisk();
        this->count--;
        diskToReturn->setNextDisk(0);
        return diskToReturn;
    }
    return 0;
}
        
Disk* Tower::peek()
{
    return this->top;
}

void Tower::display()
{
    std::cout << "Tower " << this->towerNumber << "\n";
    Disk* currDisk = this->top;
    for(int i = 0; i < this->count; i++)
    {
        currDisk->display();
        currDisk = currDisk->getNextDisk();
    }
    std::cout << "__________\n";
}