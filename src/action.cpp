//here are all the function's declared
#include <iostream>
#include "include/actions.h"

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
    std::cout << "Type: ";
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
        std::cout << "season: ";
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

Article* search_Article(TireCenter &tirecenter){
    int choiceFilter;
    std::vector<Article*> articles;
    articles = tirecenter.getArticles();    
    
    do{
    std::cout << "Waarop wilt u filteren: "
        << "\n\t1.Banden" << "\n\t2.Velgen" << "\n\t3.Groote" << std::endl;
    std::cin >> choiceFilter;
    
    if(choiceFilter < 0 || choiceFilter > 3){
        std::cout << "Kies een geldige optie [1-3]!" << std::endl;
    }
    }while(choiceFilter < 0 || choiceFilter > 3);

    switch (choiceFilter){
    case 1:
        filterTires(articles);
        break;
    case 2:filterRims(articles);
        break;
    case 3:
        filterSize(articles);
        break;
    }

    return 0;
}

Article* filterTires(std::vector<Article*> articles){
    int i = 0;  //i is the index of the vector articles where the article is stored


    std::cout << "----------Tires----------"<< std::endl;

    for(Article* article : articles){
            if(article->getType() == 't'){
            article->print();
            i++;
        }
    }
    if(i == 0){
        std::cout << "Er werd geen artikel gevonden. \n";
    }
    return 0;
}
Article* filterRims(std::vector<Article*> articles){
    int i = 0;  //i is the index of the vector articles where the article is stored
    
    std::cout << "----------Rim----------"<< std::endl;

    for(Article* article : articles){
            if(article->getType() == 'r'){
            article->print();
            i++;
        }
    }
    if(i == 0){
        std::cout << "Er werd geen artikel gevonden. \n";
    }
    return 0;
}
Article* filterSize(std::vector<Article*> articles){
    int i = 0;  //i is the printcounter, if i = 0 there are no elements printed or found
    int size;

    std::cout << "----------Tires/Rims----------"<< std::endl;

    std::cout << "Op welke size wil je filteren: ";
    std::cin >> size;

    for(Article* article : articles){
            if(article->getDiameter() == size){
            article->print();
            i++;
        }
    }

    if(i == 0){
        std::cout << "Er werd geen artikel gevonden. \n";
    }
    return 0;
}
