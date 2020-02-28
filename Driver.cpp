#include "Tower.hpp"
#include <iostream>

int display(Tower* Tower_1, Tower* Tower_2, Tower* Tower_3 ){
        Tower_1->display();
        Tower_2->display();
        Tower_3->display();
        int val;
        std::cout << "Enter the tower to move from: ";
        std::cin >> val;
        return val;
}
int newTowerNum(){
    int val;
    std::cout << "\nEnter the tower to move to: ";
    std::cin >> val;
    return val;
}

int main()
{
    bool victory = false;//win condition
    //Towers
    Tower* Tower_1 = new Tower(1);
    Tower* Tower_2 = new Tower(2);
    Tower* Tower_3 = new Tower(3);

    //Tower Array to organize
    Tower* TowerArray[3] = {Tower_1, Tower_2, Tower_3};
    
    //Initializes values in first tower
    for(int i = 3; i >= 1; i--){
        Tower_1->push(new Disk(i));
    }

    int moves = 0;
    int TowerNumberFrom;
    int TowerNumberTo;
    int numFrom;

    while(victory == false){//loop that runs until the victory condition is met
        bool compare = false;

        while(compare == false) {//loop that runs until the move is valid
        TowerNumberFrom = display(Tower_1, Tower_2, Tower_3);//gets the tower to move from
        
        while(TowerArray[TowerNumberFrom - 1]->getCount() == 0){//can't select from a tower that has no items
                std::cout << "Invalid move\n";
                TowerNumberFrom = display(Tower_1, Tower_2, Tower_3);
        }

        numFrom = TowerArray[TowerNumberFrom - 1]->peek()->getSize();
        TowerNumberTo = newTowerNum();

        if(TowerArray[TowerNumberTo - 1]->getCount() == 0){//checks to see if the move is valid
          compare = true;  
        } else if (numFrom < TowerArray[TowerNumberTo - 1]->peek()->getSize()){
            compare = true; 
        } else{
            std::cout << "Invalid move\n";
        }
        
    }
        TowerArray[TowerNumberTo - 1]->push(TowerArray[TowerNumberFrom - 1]->pop());//moves the disc
        moves++;
        std::cout << "The amout of moves currently is: " << moves << "\n";
        if(TowerArray[2]->getCount() == 3){//looks for all three items in the last tower to win
            victory = true;
        }
        
    }

    std::cout << "\n You win in " << moves << " moves!" << "\n";
    
    
    delete Tower_1;
    delete Tower_2;
    delete Tower_3;
    
    return 0;
}