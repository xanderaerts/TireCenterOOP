#include <iostream>
#include <string>
#include "user.h"
#include "user.cpp"


void Login();
int printMenu(std::string role);


User user;

void Login(){
   
    if(user.getRole() == "admin"){
        std::string inputPass;
        std::cout << "Passwoord: ";
        std::cin >> inputPass;

        if(inputPass == user.getPassword()){
            std::cout << ("toegang") << std::endl; 
            printMenu(user.getRole());
        }
        else{
            std::cout << ("wrong");
            
        }
    }
    
}

int printMenu(std::string role){
    int choice;

    std::cout << "Welkom" << user.getUsername() << std::endl;
    std::cout << "_____________" << std::endl;
    std::cout << "Maak een keuze: " << std::endl;
    std::cout << "\t1.Bestellingen" << std::endl;    
    std::cout << "\t2.Artikkels (zoeken/voorraad)" << std::endl;
    std::cout << "\t3.Klantenbeheer" << std::endl;
    std::cout << "\t4.Facturatie" << std::endl;
    std::cin >> choice;

    switch(choice){
        case 1:
            if(role == "admin"){
                std::cout << "opties" << std::endl;
            }
    }



    

}
