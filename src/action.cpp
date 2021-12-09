//here are all the function's declared
#include <iostream>
#include "include/actions.h"

std::vector<std::string> askNewArticleData(){
    std::vector<std::string> articleData;
    std::string input;
    std::string articleDataMembers[6] ={"naam","manufacturer","stock","diameter","price"};

    std::cout << "Geef de volgende gegevens van het artikel in: " << std::endl;
    


    return articleData;
}

std::vector<std::string> askNewTireData(){
    std::vector<std::string> TireData;
    std::string input;
    std::string articleDataMembers[4] ={"width","height","speedindex","season(only one char)"};

    std::cout << "Geef de volgende gegevens van de band in: " << std::endl;
    
    

    return TireData;
}

std::vector<std::string> askNewRimData(){
    std::vector<std::string> RimData;
    std::string input;
    std::string articleDataMembers[3] ={"aluminium","color","width"};

    std::cout << "Geef de volgende gegevens van de velg in: " << std::endl;
    
    for(int i=0;i<3;i++){        
        std::cout << articleDataMembers[i] << ": ";
        std::cin >> input;
        RimData.push_back(input);
    }

    return RimData;
}

void add_Article(TireCenter &tirecenter){
    char type;
    std::string name,manufacturer;
    int stock,diameter;
    float price;
    std::vector<Article*> Articles;

    std::cout << "Geef de volgende gegeven van het nieuwe artikel in: ";
    std::cout << "naam: ";
    std::cin.ignore();
    getline(std::cin,name);
    std::cout << "Manufacturer: ";
    std::cin >> manufacturer;
    std::cout << "Stock: ";
    std::cin >> stock;
    std::cout << "Diameter: ";
    std::cin >> diameter;
    std::cout << "Price: ";
    std::cin >> price;
    std::cout << "Type";
    std::cin >> type;

    if(type == 't'){
        int width,height;
        std::string speedindex;
        char season;

        std::cout << "width: ";
        std::cin >> width;
        std::cout << "height: ";
        std::cin >> height;
        std::cout << "Speedindex: ";
        std::cin >> speedindex;
        std::cout << "season ";
        std::cin >> season;
        
        Articles = tirecenter.getArticles();
        Articles.push_back(new Tire(name,manufacturer,stock,diameter,price,type,width,height,speedindex,season));
        tirecenter.setArticles(Articles);
    }
    else if(type == 'r'){
        bool aluminium;
        std::string color;
        int width;

        std::cout << "Aluminium? (1=true,0=false): ";
        std::cin >> aluminium;
        std::cout << "Color: ";
        std::cin >> color;
        std::cout << "width: ";
        std::cin >> width;
        
        Articles = tirecenter.getArticles();
        Articles.push_back(new Rim(name,manufacturer,stock,diameter,price,type,aluminium,color,width));
        tirecenter.setArticles(Articles);
    }
}

