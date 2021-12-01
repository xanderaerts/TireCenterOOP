#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include "include/user.h"
#include "include/menu.h"


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
        std::cout << choice << std::endl;
        
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

void Login(){
    int attemps=0;
    std::string inputPass="",inputUsername;

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
                std::cout << "Toegang geweigerd, te veel pogingen!" << std:: endl;
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
                user.setUsername(inputUsername);
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
    int choice=-1;

    std::cout << "\n\n";
    std::cout << "Welkom " << user.getUsername() << std::endl;
    std::cout << "--------------" << std::endl;
    
    while(choice<0 || choice > 4){

        std::cout << "\t1.Bestellingen" << std::endl;    
        std::cout << "\t2.Artikels (zoeken/voorraad)" << std::endl;
        std::cout << "\t3.Klantenbeheer" << std::endl;
        std::cout << "\t4.Facturatie" << std::endl;
        std::cout << "Maak een keuze: ";
        std::cin >> choice;

        switch(choice){
            case 1:
                if(user.getRole() == "admin"){
                    std::vector<Menu> list{addOrder};
                    //std::vector<Menu> list{addOrder};
                    printMenu2(list);
                }
                else if(user.getRole() == "worker"){
                    std::vector<Menu> list{addOrder};
                    printMenu2(list);
                }
                break;
            
            case 2:
                if(user.getRole() == "admin"){
                    std::vector<Menu> list{searchArtcle,addArticle,rmArticle,editArticle};
                    printMenu2(list);
                }
                else if(user.getRole() == "worker"){
                    std::vector<Menu> list{searchArtcle,editArticle};
                    printMenu2(list);
                }    
                break;
            
            case 3:
                if(user.getRole() == "admin"){
                    std::vector<Menu> list{addCust,searchCust,editCust};
                    printMenu2(list);
                }
                else if(user.getRole() == "worker"){
                    std::vector<Menu> list{addCust,searchCust};
                    printMenu2(list);
                }
                break;
            
            case 4:
                if(user.getRole() == "admin"){
                    std::vector<Menu> list{addInvoice,searchInvoice};
                    printMenu2(list);
                }
                else if(user.getRole() == "worker"){
                    std::vector<Menu> list{searchInvoice,addInvoice};
                    printMenu2(list);
                }
                break;
            default:
            std::cout << "Maak een geldige keuze!"<<std::endl;
                continue;
        }
    }
}