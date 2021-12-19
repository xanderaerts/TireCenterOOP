#include "include/menu.h"
#include <string>
#include <vector>
#include <iostream>

Menu menu;

std::string useCaseToString(Menu inputUseCase){
    switch(inputUseCase){
        case addOrder:
            return "Bestelling toevoegen";break;
        case searchArticle:
            return "Artikel opvragen";break;
        case addArticle:
            return "Artikel toevoegen";break;
        case rmArticle:
            return "Artikel verwijderen";break;
        case editArticle:
            return "Artikel bewerken";break;
        case addCust:
            return "Klant toevoegen";break;
        case searchCust:
            return "Klant opvragen";break;
        case editCust:
            return "Klant bewerken";break;
        case deleteCust:
            return "Klant verwijderen";break;
        case checkInvoice:
            return "Factuur opvragen";break;
        case goBack:
            return "Terug";break;
    }
    return 0;
}

void printMenuUseCase(TireCenter &tirecenter,User user){
    int choiceUseCaseGroup=-1;
    std::string titels[3] = {"\n-----Bestellingen-----","\n-----Artikels-----","\n-----Klanten-----"};

    std::cout << "\n\n";
    std::cout << "Welkom " << user.getUsername() << std::endl;
    std::cout << "--------------" << std::endl;
    
    while(choiceUseCaseGroup<0 || choiceUseCaseGroup > 3){

        std::cout << "\t1.Bestellingen" << std::endl;    
        std::cout << "\t2.Artikels (zoeken/voorraad)" << std::endl;
        std::cout << "\t3.Klantenbeheer" << std::endl;
        std::cout << "\t4.Afsluiten" << std::endl;
        std::cout << "Maak een keuze: ";
        std::cin >> choiceUseCaseGroup;

        switch(choiceUseCaseGroup){
            case 1:
                std::cout << titels[0];
                if(user.getRole() == "admin"){
                    std::vector<Menu> UseCaseFunctions{addOrder,checkInvoice,goBack};
                    printMenuUseCaseDetails(UseCaseFunctions,tirecenter,user);
                }
                else if(user.getRole() == "worker"){
                    std::vector<Menu> UseCaseFunctions{addOrder,checkInvoice,goBack};
                    printMenuUseCaseDetails(UseCaseFunctions,tirecenter,user);
                }
                break;
            case 2:
            std::cout << titels[1];
                if(user.getRole() == "admin"){
                    std::vector<Menu> UseCaseFunctions{addArticle,searchArticle,rmArticle,editArticle,goBack};
                    printMenuUseCaseDetails(UseCaseFunctions,tirecenter,user);
                }
                else if(user.getRole() == "worker"){
                    std::vector<Menu> UseCaseFunctions{editArticle,searchArticle,goBack};
                    printMenuUseCaseDetails(UseCaseFunctions,tirecenter,user);
                }    
                break;
            
            case 3:
            std::cout << titels[2];
                if(user.getRole() == "admin"){
                    std::vector<Menu> UseCaseFunctions{addCust,searchCust,editCust,deleteCust,goBack};
                    printMenuUseCaseDetails(UseCaseFunctions,tirecenter,user);
                }
                else if(user.getRole() == "worker"){
                    std::vector<Menu> UseCaseFunctions{addCust,searchCust,goBack};
                    printMenuUseCaseDetails(UseCaseFunctions,tirecenter,user);
                }
                break;
            case 4:
                saveAll(tirecenter);
                exit(-1);
                //saving
            default:
            std::cout << "\nMaak een geldige keuze!"<<std::endl;
                continue;
        }
    }
}

void printMenuUseCaseDetails(std::vector<Menu>UseCaseFunctions,TireCenter &tirecenter,User user){

    std::string option,test;
    int choice=1,lineNr{1};
    bool exit = false;


    while(!exit){
        std::cout << "\n\n";
        for(Menu i : UseCaseFunctions){
            option = useCaseToString(i);
            std::cout /*<< "\t" */ << lineNr<< ": " << option << std::endl;
            lineNr++;        
        }

        std::cout << "\nMaak een keuze: ";
        std::cin >> choice;
        lineNr = 1;
        Menu useCaseChoice = UseCaseFunctions[choice-1];
    
        switch(useCaseChoice){
            case addOrder:
                add_Order(tirecenter);
                break;
            case searchArticle:
                search_Article(tirecenter,false);
                break;
            case addArticle:
                add_Article(tirecenter);
                break;
            case rmArticle:
                delete_Articles(tirecenter);
                break;
            case editArticle:
                edit_Article(tirecenter);
                break;
            case addCust:
                add_Customer(tirecenter);
                break;
            case searchCust:
                search_Customer(tirecenter);
                break;
            case editCust:
                edit_Customer(tirecenter);
                break;
            case deleteCust:
                delete_Customer(tirecenter);
                break;
            case checkInvoice:
                check_Invoices(tirecenter);
                break;
            case goBack:
                printMenuUseCase(tirecenter,user);
                break;
            default:
                std::cout << "\n\nMaak een geldige keuze!" << std::endl;
                continue;
        }
    }
}
