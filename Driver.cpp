#include "Stack.hpp"
#include <iostream>

int display(Stack* stack_1, Stack* stack_2, Stack* stack_3 ){
        stack_1->display();
        std::cout << "-----------------------------------------\n";
        stack_2->display();
        std::cout << "-----------------------------------------\n";
        stack_3->display();
        std::cout << "-----------------------------------------\n";
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
    bool victory = false;
    Stack* stack_1 = new Stack();
    Stack* stack_2 = new Stack();
    Stack* stack_3 = new Stack();

    Stack* stackArray[3] = {stack_1, stack_2, stack_3};
    
    for(int i = 3; i >= 1; i--){
        stack_1->push(i);
    }

    int moves = 0;
    int stackNumberFrom;
    int stackNumberTo;
    int numFrom;

    while(victory == false){//loop that runs until the victory condition is met
        bool compare = false;

        while(compare == false) {
        stackNumberFrom = display(stack_1, stack_2, stack_3);//gets the tower to move from
        
        if(stackNumberFrom != 1 && moves == 0){
            while(stackNumberFrom != 1){
                std::cout << "Invalid move\n";
                stackNumberFrom = display(stack_1, stack_2, stack_3);
            }
        } else if (stackArray[stackNumberFrom - 1]->isEmpty()){
                while(stackArray[stackNumberFrom - 1]->isEmpty()){
                    std::cout << "Invalid move\n";
                    stackNumberFrom = display(stack_1, stack_2, stack_3);
                }
        } else {

        int numFrom = stackArray[stackNumberFrom - 1]->peek();
        stackNumberTo = newTowerNum();

        if(stackArray[stackNumberTo - 1]->isEmpty() == true){
          compare = true;  
        } else if (numFrom < stackArray[stackNumberTo - 1]->peek()){
            compare = true; 
        } else{
            std::cout << "Invalid move\n";
            }
        }
    }
        stackArray[stackNumberTo - 1]->push(stackArray[stackNumberFrom - 1]->pop());
        moves++;

        if(stackArray[0]->isEmpty() && stackArray[1]->isEmpty()){
            victory = true;
        }
        
    }

    std::cout << "\n You win!";
    
    delete stack_1;
    delete stack_2;
    delete stack_3;

    return 0;
}
