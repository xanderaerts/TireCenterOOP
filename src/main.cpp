#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include "user.h"
#include "user.cpp"
#include "menu.cpp"


void Login();
void printMenu();

User user;

int main(){
    int choice = 0;
    int logged = 0;

    do{
        if(logged == 1){
            printMenu();
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
                Login();
                logged = 1;
                break;
            case 2:
                user.setRole("worker");
                Login();
                logged = 1;
                break;
            case 3:
                std::cout << "Tot ziens!";
                logged = 0;
                break;
            default:
                std::cout <<"Kies een juiste optie!";
                break;
        }

    }while(choice != 3);
    return 0;
}

void Login(){

    int attemps;
    std::string inputPass,inputUsername;

    if(user.getRole() == "admin"){

        while(attemps < 4 && inputPass != user.getPassword()){
            std::cout << "Username: ";
            std::cin >> inputUsername;
            std::cout << "Passwoord: ";
            std::cin >> inputPass;
            attemps++;

            if(inputPass == user.getPassword()){
                user.setUsername(inputUsername);
                printMenu();
            }
            else if(attemps > 3){
                std::cout << "Acces denied" << std:: endl;
                exit(-1);
            }
        }
    }

    if(user.getRole() == "worker"){

        while(attemps < 4 && inputPass != user.getPassword()){
            std::cout << "Username: ";
            std::cin >> inputUsername;
            std::cout << "Passwoord: ";
            std::cin >> inputPass;
            attemps++;

            if(inputPass == user.getPassword()){
                printMenu();
            }
            else if(attemps > 3){
                std::cout << "Acces denied" << std:: endl;
                exit(-1);
            }
        }
    }    
}

void printMenu(){
    int choice,choice2;
    bool validChoice=false;

    while(true){

    std::cout << "Welkom " << user.getUsername() << std::endl;
    std::cout << "--------------" << std::endl;
    std::cout << "Maak een keuze: " << std::endl;
    std::cout << "\t1.Bestellingen" << std::endl;    
    std::cout << "\t2.Artikkels (zoeken/voorraad)" << std::endl;
    std::cout << "\t3.Klantenbeheer" << std::endl;
    std::cout << "\t4.Facturatie" << std::endl;
    std::cin >> choice;

    std::cout << "Maak een keuze: " << std::endl;

    switch(choice){
        case 1:
            if(user.getRole() == "admin"){
                std::vector<Menu> list{addOrder};
                choice2 = printMenu2(list);
            }
            else if(user.getRole() == "worker"){
                std::vector<Menu> list{addOrder};
                choice2 = printMenu2(list);
            }
            break;
        
        case 2:
            if(user.getRole() == "admin"){
                std::vector<Menu> list{searchArtcle,addArticle,rmArticle,editArticle};
                choice2 = printMenu2(list);
            }
            else if(user.getRole() == "worker"){
                std::vector<Menu> list{searchArtcle,editArticle};
                choice2 = printMenu2(list);
            }    
            break;
        
        case 3:
            if(user.getRole() == "admin"){
                std::vector<Menu> list{addCust,searchCust,editCust};
                choice2 = printMenu2(list);
            }
            else if(user.getRole() == "worker"){
                std::vector<Menu> list{addCust,searchCust};
                choice2 = printMenu2(list);
            }
            break;
        
        case 4:
            if(user.getRole() == "admin"){
                std::vector<Menu> list{addInvoice,searchInvoice};
                choice2 = printMenu2(list);
            }
            else if(user.getRole() == "worker"){
                std::vector<Menu> list{searchInvoice,addInvoice};
                choice2 = printMenu2(list);
            }
            break;
        }
    }
}