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

int search_Article(TireCenter &tirecenter,bool unicChoice){
    int choiceFilter,i=0;
    std::vector<Article*> articles;
    Article* foundArticle{};
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
        foundArticle = filterTires(articles,unicChoice);
        break;
    case 2:
        foundArticle = filterRims(articles,unicChoice);
        break;
    case 3:
        foundArticle = filterSize(articles,unicChoice);
        break;
    }

    if(foundArticle){

    for(Article* a : articles){
        if(a== foundArticle){
            return i; 
        }
        i++;
    }}
    return 0;
}

Article* filterTires(std::vector<Article*> articles,bool unicChoice){
    int i=0,choice=0;
    std::vector<Article*> printedArticles;

    std::cout << "\n----------Tires----------\n"<< std::endl;

    for(Article* article : articles){
        if(article->getType() == 't'){
            i++;
            std::cout <<"\n" << i <<": " << std::endl;
            article->print();
            printedArticles.push_back(article);
            }
    }
    if(i == 0){
        std::cout << "\nEr werd geen artikel gevonden. \n";
        unicChoice = false;
    }
    if (unicChoice) {
        std::cout << "Welk artikel wil je kiezen: ";
        std::cin >> choice;
        choice--;

        std::cout << choice;
        return printedArticles[choice];
    }
}

Article* filterRims(std::vector<Article*> articles,bool unicChoice){
    int i=0,choice=0;

    std::vector<Article*> printedArticles;
    
    std::cout << "\n----------Rim----------\n"<< std::endl;
    for(Article* article : articles){
        if(article->getType() == 'r'){
            std::cout <<"\n" << i + 1<<": " << std::endl;
            article->print();
            printedArticles.push_back(article);
            i++;
        }
    }
    if(i == 0){
        std::cout << "\nEr werd geen artikel gevonden. \n";
        unicChoice = false;
    }

    if(unicChoice){
        std::cout << "Welk artikel wil je kiezen: ";
        std::cin >> choice;
        choice--;;
        return printedArticles[choice];

    }
}

Article* filterSize(std::vector<Article*> articles,bool unicChoice){
    int i=0,choice=0;
    int size;
    std::vector<Article*> printedArticles;

    std::cout << "\n----------Tires/Rims----------\n"<< std::endl;
    std::cout << "Op welke size wil je filteren: ";
    std::cin >> size;

    for(Article* article : articles){
            if(article->getDiameter() == size){
                article->print();  
                printedArticles.push_back(article);
                i++;
        }
    }
    if(i == 0){
        std::cout << "\nEr werd geen artikel gevonden. \n";
        unicChoice = false;
    }

    if(unicChoice){
        std::cout << "\nWelk artikel wil je kiezen: ";
        std::cin >> choice;
        choice--;
        return printedArticles[choice];

    }
}

void delete_Articles(TireCenter &tirecenter){
    std::vector<Article*> articles = tirecenter.getArticles();
    int index = search_Article(tirecenter,true);
    std::cout << "index : "<< index << std::endl;
    articles.erase(articles.begin() + (index));
    tirecenter.setArticles(articles);
}







