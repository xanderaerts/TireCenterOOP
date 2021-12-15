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

    for(auto a : articles){
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

    for(auto article : articles){
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
    for(auto article : articles){
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

    for(auto article : articles){
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
    Article* article = articles[index];
    articles.erase(articles.begin() + (index));
    delete article;
    tirecenter.setArticles(articles);
}

void edit_Article(TireCenter &tirecenter){
    std::vector<Article*> articles = tirecenter.getArticles();
    int index = search_Article(tirecenter,true);
    int choice{};

    if(index >= 0 && index < (int)articles.size()){
        Article* article = articles[index];
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
    char choiceType;
    int volumeDiscount{};

    std::cout << "\nGeef de naam van de klant in: "; 
    std::cin.ignore();
    getline(std::cin,name);
    std::cout << "Geef het adres van de klant in: ";
    //std::cin.ignore();
    getline(std::cin,address);
    std::cout << "Is het een bedrijfsklant?(c=ja,p=nee)";
    std::cin >> choiceType;

    std::vector<Customer*> customers;
    tirecenter.getCustomers();

    switch (choiceType)
    {
    case 'c':
        std::cout << "Geef het btw nummer van de klant in: ";
        std::cin.ignore();
        getline(std::cin,VATNr);
        std::cout << "Geef de korting in: ";
        std::cin >> volumeDiscount;
        
        customers.push_back(new Company(name,address,choiceType,VATNr,volumeDiscount));
        break;

    case 'p':
        customers.push_back(new Customer(name,address,choiceType));
        break;        
    }

    tirecenter.setCustomers(customers);
}

int search_Customer(TireCenter &tirecenter){
    int choice, indexFoundCustomer=-1;

    do{
    std::cout << "Waarop wil je filteren: " << std::endl
    << "\t1.Particulieren\n" << "\t2.Bedrijfsklanten\n" << "\t3.Zoeken op naam" << std::endl << "Maak een keuze: ";

    std::cin >> choice;
    }while(choice <= 0 && choice > 3);

    std::vector<Customer*> customers = tirecenter.getCustomers();
    switch(choice){
        case 1:
            filter_Private(tirecenter);
            break;
        case 2:
            filter_Company(tirecenter);
            break;
        case 3:
            indexFoundCustomer = filter_Customer_Name(tirecenter);
            break;
    }
    return indexFoundCustomer;
}

void filter_Private(TireCenter &tirecenter){
    int i=0;
    std::vector<Customer*> customers;
    customers = tirecenter.getCustomers();
    
    for(auto customer : customers){
        if(customer->getType() == 'p'){
            i++;
            std::cout << i  << ":";
            customer->printCustomer();
        }
    }
}

void filter_Company(TireCenter &tirecenter){
    int i=0;
    std::vector<Customer*> customers;
    customers = tirecenter.getCustomers();
    
    for(auto customer : customers){
        if(customer->getType() == 'c'){
            i++;
            std::cout << i  << ":";
            Company* comp = dynamic_cast<Company*>(customer);
            comp->printCompany();
        }
    }
}

int filter_Customer_Name(TireCenter &tirecenter){
    std::string name;
    std::vector<Customer*> customers;
    customers = tirecenter.getCustomers();
    //Sustomer* foundCustomer;
    int i = 0;

    std::cout << "Geef de naam van de klant in: ";
    std::cin.ignore();
    getline(std::cin,name);

    for(auto customer : customers){
        if (name == customer->getName()) {
            if (customer->getType() == 'c') {
                Company* comp = dynamic_cast<Company*>(customer);
                comp->printCompany();
            }
            else if (customer->getType() == 'p') {
                customer->printCustomer();
            }
            return i;
            break;
        }
        i++;
    } 
    return -1;
}

void edit_Customer(TireCenter &tirecenter){
    std::vector<Customer*> customers;
    Customer* customer;
    int choice;
    int index = filter_Customer_Name(tirecenter);
    
    customers = tirecenter.getCustomers();
    
    if(index >= 0 && index < (int)customers.size()){
        customer = customers[index];

    do{
            std::cout << "Welk item wil je bewerken: " << "\n Het veranderen van type klant is niet mogelijk hier voor moet je de klant verwijderen en weer toevoegen." 
            << "\n\t1.Naam" << "\n\t2.adres";
            if(customer->getType() == 'c'){
                std::cout << "\n\t3.BTW nr" << "\n\t4.Korting" << std::endl;
            }
            std::cout << "\nMaak een keuze: ";
            std::cin >> choice;
        }while(choice < 1 && (choice > 2 && customer->getType() != 'c') && (choice < 4));

    
        if(choice == 1){
            std::string newName;
            std::cout << "\nGeef de nieuwe naam in: ";
            std::cin >> newName;
            customer->setName(newName);
        }
        else if(choice == 2){ 
            std::string NewAdr;
            std::cout << "\nGeef het nieuwe adres in: ";
            std::cin >> NewAdr;
            customer->setAddress(NewAdr);
        }
        else if(choice == 3){
            std::string newVAT;
            std::cout << "\nGeef het nieuwe BTWNr in: ";
            std::cin >> newVAT;
            Company* comp = dynamic_cast<Company*>(customer);
            comp->setVATNr(newVAT);
        }
        else if(choice == 4){
            int newVolumeDiscount;
            std::cout << "Geef de nieuwe korting in: ";
            std::cin >> newVolumeDiscount;
            Company* comp = dynamic_cast<Company*>(customer);
            comp->setVolumeDiscount(newVolumeDiscount);
        } 
    }   
}

void delete_Customer(TireCenter &tirecenter){
    std::vector<Customer*> customers = tirecenter.getCustomers();
    int index = filter_Customer_Name(tirecenter);
    Customer* customer = customers[index];
    customers.erase(customers.begin()+ (index));
    delete customer;
    tirecenter.setCustomers(customers);
}

void add_Order(TireCenter &tirecenter){
    Invoice* invoice = new Invoice;
    std::vector<Article*> articles_On_Invoice;

    std::cout << "Voor welke klant wil je een order plaatsen?" << std::endl;
    int indexCustomer = filter_Customer_Name(tirecenter);
    std::vector<Customer*> customers = tirecenter.getCustomers();
    Customer* customer = customers[indexCustomer];

    Customer* copyCust = customer->makecopy();
    invoice->setCustomer(copyCust);

    std::vector<Article*> articles = tirecenter.getArticles();
    Article* article;

    int choice,amount,stockUpdate;
    std::cout << "Welk artikel wil je toevoegen aan dit order?" << std::endl;
    do{
        int indexArticle = search_Article(tirecenter,true);
        article = articles[indexArticle];
        Article* copyArt;
        copyArt = article->makeCopy();

        std::cout << "Hoeveel wil je er van " << copyArt->getName() << std::endl << "Aantal: ";
        std::cin >> amount;

        if(article->getStock() > amount){
            stockUpdate = article->getStock() - amount;
            copyArt->setStock(amount);
            article->setStock(stockUpdate);

            articles_On_Invoice.push_back(copyArt);
        }
        else{
            std::cout << "Er is niet genoeg op voorraad van dit artikel" << std::endl << "Naam: " << article->getName()
                << "Huidige voorraad: " << article->getStock() << std::endl;
        }
         
        std::cout << "Wil je nog een artikel toevoegen? (1=ja,0=nee)" << std::endl;
        std::cout << "Maak een keuze: ";
        std::cin >> choice;       

    }while(choice == 1);

    invoice->setArticles(articles_On_Invoice);
    
    std::vector<Invoice*> invoices_In_TireCenter = tirecenter.getInvoices();
    invoices_In_TireCenter.push_back(invoice);
}


