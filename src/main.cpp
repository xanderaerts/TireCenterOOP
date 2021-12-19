#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <fstream>

#include "include/user.h"
#include "include/menu.h"
#include "include/tireCenter.h"
#include "include/tire.h"
#include "include/filehandeling.h"

void authenticateUser();
User user;
TireCenter tirecenter;

int main(){


    int choice = 0;
    int logged = 0;

    loadAll(tirecenter);
    saveAll(tirecenter);

    
    do{
        if(logged == 1){
            printMenuUseCase(tirecenter,user);
        }
        
        std::cout << "-----Login-----" << std::endl;
        std::cout << "\t1.Manager" << std::endl;
        std::cout << "\t2.Werknemer" << std::endl;
        std::cout << "\t3.Logout" << std::endl;
        std::cout << "Maak een keuze: ";
        std::cin >> choice;
        switch(choice){
            case 1:
                /*naar file schrijven welke activce user is ofzo iets we vinden wel iets*/
                user.setRole("admin");
                authenticateUser();
                logged = 1;
                break;
            case 2:
                user.setRole("worker");
                authenticateUser();
                logged = 1;
                break;
            case 3:
                std::cout << "Tot ziens!" << std::endl;
                logged = 0;
                break;
            default:
                std::cout <<"\n\nKies een juiste optie! [1-3]" << std::endl;
                break;
        }

    }while(choice != 3);
    return 0;
}

void authenticateUser(){
    int attemps=0;
    std::string inputPass="",inputUsername;

    while(attemps <= 3 && inputPass != user.getPassword()){
        std::cout << "Username: ";
        std::cin >> inputUsername;
        std::cout << "Passwoord: ";
        std::cin >> inputPass;
        attemps++;
        if(inputPass != user.getPassword()){
            std::cout << "Het passwoord was niet correct." << std::endl;
        }

        if(inputPass == user.getPassword()){
            user.setUsername(inputUsername);
            printMenuUseCase(tirecenter,user);
        }
        else if(attemps >= 3){
            std::cout << "Toegang geweigerd, te veel pogingen!" << std:: endl;
            exit(-1);
        }
    }    
}

