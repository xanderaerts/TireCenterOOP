//here are all the function's declared
#include <iostream>
#include "include/actions.h"

#define DATAMEMBART 6
#define TIREDATAMEMB 4
#define RIMDATAMEMB 3

//all fuction's about the articles
void add_Article(TireCenter &tirecenter){
    char type;
    std::string name,manufacturer;
    int stock,diameter;
    float price;
    std::vector<Article*> Articles;
    Articles = tirecenter.getArticles();

    std::cout << "Geef de volgende gegeven van het nieuwe artikel in: ";
    std::cout << "\nnaam: ";
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

    do{
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
            
            Articles.push_back(new Rim(name,manufacturer,stock,diameter,price,type,aluminium,color,width));
            tirecenter.setArticles(Articles);
        }
        else{
            std::cout << "\n Geef een geldige keuze in! (t/r)" << std::endl;
        }
    }while(type != 't' || type != 'r');
}

int search_Article(TireCenter &tirecenter,bool unicChoice){
    int choiceFilter,i=0;
    std::vector<Article*> articles;
    Article* foundArticle{};
    articles = tirecenter.getArticles();    
    
    do{
    std::cout << "\n\n\nWaarop wilt u filteren: "
        << "\n\t1.Banden" << "\n\t2.Velgen" << "\n\t3.Groote" << std::endl 
        << "Maak een keuze: ";
    std::cin >> choiceFilter;
    
    if(choiceFilter < 0 || choiceFilter > 3){
        std::cout << "\nKies een geldige optie [1-3]!" << std::endl;
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
    return -1;
}

Article* filterTires(std::vector<Article*> articles,bool unicChoice){
    int i=0,choice=0;
    std::vector<Article*> printedArticles;

    std::cout << "\n----------Tires----------\n"<< std::endl;

    for(Article* article : articles){
        if(article->getType() == 't'){
            i++;
            std::cout <<"\n" << i <<": ";
            article->print();
            printedArticles.push_back(article);
            }
    }
    if(i == 0){
        std::cout << "\nEr werd geen artikel gevonden. \n";
        unicChoice = false;
    }
    if (unicChoice) {
        do{
        std::cout << "\nWelk artikel wil je kiezen: ";
        std::cin >> choice;
        choice--;
        }while(choice < 0 || choice >= (int)printedArticles.size());
        return printedArticles[choice];
    }
    return 0;
}

Article* filterRims(std::vector<Article*> articles,bool unicChoice){
    int i=0,choice=0;

    std::vector<Article*> printedArticles;
    
    std::cout << "\n----------Rim----------\n"<< std::endl;
    for(Article* article : articles){
        if(article->getType() == 'r'){
            std::cout <<"\n" << i + 1<<": ";
            article->print();
            printedArticles.push_back(article);
            i++;
        }
    }
    if(i == 0){
        std::cout << "\nEr werd geen artikel gevonden. \n";
        unicChoice = false;
    }

    if (unicChoice) {
        do{
        std::cout << "\nWelk artikel wil je kiezen: ";
        std::cin >> choice;
        choice--;
        }while(choice < 0 || choice >= (int)printedArticles.size());
        return printedArticles[choice];
    }
    return 0;
}

Article* filterSize(std::vector<Article*> articles,bool unicChoice){
    int i=0,choice=0;
    int size;
    std::vector<Article*> printedArticles;

    std::cout << "\n----------Tires/Rims----------\n"<< std::endl;
    std::cout << "\nOp welke size (diameter) wil je filteren: ";
    std::cin >> size;

    for(Article* article : articles){
            if(article->getDiameter() == size){
                std::cout <<"\n" << i + 1<<": ";
                article->print();  
                printedArticles.push_back(article);
                i++;
        }
    }
    if(i == 0){
        std::cout << "\nEr werd geen artikel gevonden. \n";
        unicChoice = false;
    }

    if (unicChoice) {
        do{
        std::cout << "\nWelk artikel wil je kiezen: ";
        std::cin >> choice;
        choice--;
        }while(choice < 0 || choice >= (int)printedArticles.size());
        return printedArticles[choice];
    }
    return 0;
}

void delete_Articles(TireCenter &tirecenter){
    std::vector<Article*> articles = tirecenter.getArticles();
    int index = search_Article(tirecenter,true);
    articles.erase(articles.begin() + (index));
    tirecenter.setArticles(articles);

}

void edit_Article(TireCenter &tirecenter){
    std::vector<Article*> articles = tirecenter.getArticles();
    int index = search_Article(tirecenter,true);
    Article* article = articles[index];
    int choice{};

    if(index >= 0){
        std::cout << "\nWelk item wil je bewerken?\nVeranderen van type is niet mogelijk, verwijder hiervoor het object en maak een nieuw object aan." << std::endl;
        std::string dataMembers[DATAMEMBART-1] = {"naam","manufacturer","voorraad","diameter","prijs"};
        std::string dataMembersTire[4] = {"width","height","speedindex","season"};
        std::string dataMembersRim[3] = {"aluminium","color","string"};

        do{
            for(long signed int i = 0;i<DATAMEMBART-1;i++){
                std::cout << "\t" << i+1 << ": " << dataMembers[i] << " " << std::endl;
            }

            if(article->getType() == 't'){
                for(int i = 0;i<TIREDATAMEMB;i++){
                    std::cout << "\t" << i + 1 + DATAMEMBART-1<<": "<< dataMembersTire[i] << std::endl;
                }
                
            }
            else if(article->getType() == 'r'){
                for(int i = 0;i<RIMDATAMEMB;i++){
                    std::cout << "\t" << i + DATAMEMBART-1<<": "<< dataMembersRim[i] << std::endl;
                }
            }

            std::cout << "\nMaak een keuze: ";
            std::cin >> choice;
            choice++;
        }while(choice < 0 || choice > DATAMEMBART+TIREDATAMEMB || choice > DATAMEMBART + RIMDATAMEMB);

        if(choice <= DATAMEMBART-1){
            if(choice-1 == 1){
                std::string newName;
                std::cout << "Geef de nieuwe naam voor het article in: ";
                std::cin >> newName;
                article->setName(newName);
            }
            else if(choice - 1 == 2){
                std::string newManufacturer;
                std::cout << "Geef de nieuwe manufacturerer in: ";
                std::cin >> newManufacturer;
                article->setManufacturer(newManufacturer);
            }
            else if(choice - 1 == 3){
                int newStock;
                std::cout << "Geef de nieuwe stock in: ";
                std::cin >> newStock;
                article->setStock(newStock);
            }
            else if(choice - 1 == 4){
                int newDiameter;
                std::cout << "Geef de nieuwe diameter in: ";
                std::cin >> newDiameter;
                article->setDiameter(newDiameter);
            }
            else if(choice - 1 == 5){
                float newPrice;
                std::cout << "Geef de nieuwe prijs in: ";
                std::cin >> newPrice;
                article->setPrice(newPrice);
            }
            else{
                if(article->getType()=='t'){
                    Tire* tire = dynamic_cast<Tire*>(article);
                    if(choice == 7){
                        int newWidth;
                        std::cout << "Geef de nieuwe breedte in: ";
                        std::cin >> newWidth;
                        tire->setWidth(newWidth);                        
                    }
                    else if(choice == 8){
                        int newHeight;
                        std::cout << "Geef de nieuwe hoogte in: ";
                        std::cin >> newHeight;
                        tire->setHeight(newHeight);
                    }
                    else if(choice == 9){
                        std::string newSpeedIndex;
                        std::cout << "Geef de nieuwe speedindex in: ";
                        std::cin >> newSpeedIndex;
                        tire->setSpeedIndex(newSpeedIndex);
                    }
                    else if(choice == 10){
                        char newSeason;
                        std::cout << "Geef het nieuwe season in: ";
                        std::cin >> newSeason;
                        tire->setSeason(newSeason);
                    }
                }
                else if(article->getType() == 'r' ){
                    Rim* rim = dynamic_cast<Rim*>(article);
                    if(choice == 7){
                        bool newAluminium;
                        std::cout << "Geef de nieuwe waarde voor Aluminium in (O/1): ";
                        std::cin >> newAluminium;
                        rim->setAluminium(newAluminium);
                    }
                    else if(choice == 8){
                        std::string newColor;
                        std::cout << "Geef de nieuwe color in: ";
                        std::cin >> newColor;
                        rim->setColor(newColor);
                    }
                    else if(choice == 9){
                        int newWidth;
                        std::cout << "Geef de nieuwe breedte in: ";
                        std::cin >> newWidth;
                        rim->setWidth(newWidth);
                    }
                }
            }
        }   
    }
}

void add_Customer(TireCenter &tirecenter){
    std::string name,address,VATNr{};
    char type;
    int choiceType,volumeDiscount{};

    std::cout << "Geef de naam van de klant in: "; 
    std::cin.ignore();
    getline(std::cin,name);
    std::cout << "Geef het address van de klant in: ";
    std::cin.ignore();
    getline(std::cin,address);
    std::cout << "Is het een bedrijfsklant?(1=ja,0=nee)";
    std::cin >> choiceType;

    std::vector<Customer*> customers;



    switch (choiceType)
    {
    case 1:
        type = 'c';
        std::cout << "Geef het btw nummer van de klant in: ";
        std::cin.ignore();
        getline(std::cin,VATNr);
        std::cout << "Geef de korting in: ";
        std::cin >> volumeDiscount;
        
        customers.push_back(new Company(name,address,type,VATNr,volumeDiscount));


    case 2:
    default:
        break;
    }
}