#include "menu.h"
#include <string>
#include <vector>
#include <iostream>
Menu menu;


std::string Tostring(Menu);
int printMenu2(std::vector<Menu>);


std::string ToString(Menu m){
    switch(m){
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
        case addInvoice:
            return "Nieuw factuur aanmaken";
        case searchInvoice:
            return "Factuur opvragen";
    }
}


int printMenu2(std::vector<Menu>list){

    std::string option;
    int choice,lineNr{1};

    for(Menu i : list){
        option = ToString(i);
        std::cout << "\t" << lineNr<< ": " << option << std::endl;
        lineNr++;        
    }
    std::cout << "Maak een keuze: ";
    std::cin >> choice;


    //Menu finalChoice = list[choice];
    //std::cout << "final : " << finalChoice;


   /* switch(finalChoice){
        case 1:
            std::cout << "test";
    }*/





        

    lineNr = 1;


    return 0;
}
