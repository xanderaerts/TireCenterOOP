#include <iostream>
#include <stdlib.h>
#include <string>
#include "user.h"
#include "user.cpp"


void Login();
int printMenu();


User user;

void Login(int loggedRole){


    std::cout << loggedRole;
    int attemps;
    std::string inputPass,inputUsername;

    if(loggedRole == 1){
        user.setRole("admin");
    }
    else if(loggedRole == 2){
        user.setRole("worker");
    }
    else{
        std::cout << "User does not exist.";
        exit(-1);
    }
    std::cout << user.getRole();
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

int printMenu(){
    int choice,choice2;

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
                std::cout << "\t1.Bestelling plaatsen" << std::endl;
                
                std::cin >> choice2;
                
                
            }
            else if(user.getRole() == "worker"){
                std::cout << "\t1.Bestelling plaatsen" << std::endl;
            }
            break;
        
        case 2:
            if(user.getRole() == "admin"){
                std::cout << "\t1.Artikel opvragen" << std::endl;
                std::cout << "\t2.Artikel toevoegen" << std::endl;
                std::cout << "\t3.Artikel verwijderen" << std::endl;
                std::cout << "\t4.Artikel updaten" << std::endl;
            }
            else if(user.getRole() == "worker"){
                std::cout << "\t1.Artikel opvragen" << std::endl;
                std::cout << "\t2.Artikel updaten" << std::endl;
            }    
            break;
        
        case 3:
            if(user.getRole() == "admin"){
                std::cout << "\t1.Klant toevoegen" << std::endl;
                std::cout << "\t2.Klant opvragen" << std::endl;
                std::cout << "\t3.Klant bewerken" << std::endl;
            }
            else if(user.getRole() == "worker"){
                std::cout << "\t1.Klant toevoegen" << std::endl;
                std::cout << "\t2.Klant opvragen" << std::endl;
            }
            break;
        
        case 4:
            if(user.getRole() == "admin"){
                std::cout << "opties" << std::endl;
            }
            else if(user.getRole() == "worker"){
                std::cout << "opties worker" << std::endl;
                break;
            }

        
      


    }
}
