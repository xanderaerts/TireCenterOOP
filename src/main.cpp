#include <iostream>
#include "functions.cpp"

int main(){
    int choice = 0;
    do{
        std::cout << "-----Login-----" << std::endl;
        std::cout << "\t1.Manager" << std::endl;
        std::cout << "\t2.Werknemer" << std::endl;
        std::cout << "\t3.Stop" << std::endl;
        std::cin >> choice;
        
        switch(choice){
            case 1:
                checkOwnerPass();
                break;
            case 2:
                std::cout << "werknemer" << std::endl;
            case 3:
                std::cout << "Tot ziens!";
                break;
            default:
                std::cout <<"Kies een juiste optie!";
                break;
    }

    }while(choice != 3);
    return 0;


}