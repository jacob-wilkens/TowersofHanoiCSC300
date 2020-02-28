#include "Disk.hpp"

class Tower
{
    private:
        Disk* top;
        int count;
        int towerNumber;

    public:
        Tower(int towerNumber);
        int getCount();
        void push(Disk* d);
        Disk* pop();
        Disk* peek();
        void display();
};