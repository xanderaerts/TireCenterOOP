#include "include/menu.h"
#include <string>
#include <vector>
#include <iostream>


Menu menu;

std::string useCaseToString(Menu inputUseCase){
    switch(inputUseCase){
        case addOrder:
            return "Bestelling toevoegen";
        case searchArtcle:
            return "Artikel opvragen";
        case addArticle:
            return "Artikel toevoegen";
        case rmArticle:
            return "Artikel verwijderen";
        case editArticle:
            return "Artikel bewerken";
        case addCust:
            return "Klant toevoegen";
        case searchCust:
            return "Klant opvragen";
        case editCust:
            return "Klant bewerken";
        case searchInvoice:
            return "Factuur opvragen";
    }
    return 0;
}


void printMenuUseCaseDetails(std::vector<Menu>UseCaseFunctions,TireCenter &tirecenter){

    std::string option,test;
    int choice=1,lineNr{1};
    bool exit = false;

    
    //TODO fixing title

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
                std::cout << "addorder";
                break;
            case searchArtcle:
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
            case searchInvoice:
                std::cout << "searchInvoic";break;
            default:
                std::cout << "\n\nMaak een geldige keuze!" << std::endl;
                continue;
        }
    }
}
