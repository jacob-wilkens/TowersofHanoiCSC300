#include "Disk.hpp"
#include <iostream>

Disk::Disk(int size)
{
    this->size = size;
    this->nextDisk = 0;
}

int Disk::getSize()
{
    return this->size;
}

Disk* Disk::getNextDisk()
{
    return this->nextDisk;
}
        
void Disk::setNextDisk(Disk* d)
{
    this->nextDisk = d;
}

void Disk::display()
{
    for(int i = 0; i < this->size; i++)
    {
        std::cout << "=";
    }
    std::cout << "\n";
}