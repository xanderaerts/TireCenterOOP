#include <iostream>
#include "include/invoice.h"

#define SETTIRES 4

Invoice::Invoice(){}
Invoice::~Invoice(){}



Customer* Invoice::getCustomer(){
    return customer;
}
std::vector<Article*> Invoice::getArticles(){
    return articles;
}
float Invoice::getPrice(){
    return price;
}
int Invoice::getDiscount(){
    return discount;
}

void Invoice::setCustomer(Customer* inputCustomer){
    customer = inputCustomer;
}
void Invoice::setArticles(std::vector<Article*> inputArticles){
    articles = inputArticles;
}
void Invoice::setPrice(float inputPrice){
    price = inputPrice;
}
void Invoice::setDiscount(int inputDiscount){
    discount = inputDiscount;
}



float Invoice::calculateDiscount(){
    int sumART=0,totPrice=0,diaT,diaR;
    int volumDiscount = getDiscount();

        for(auto article : getArticles()){
            sumART += article->getStock(); //stock is the amount of articles sold on this invoice
            totPrice += article->getPrice();
        }

    if(getCustomer()->getType() == 'c'){
        sumART = sumART/4;

        if(sumART > volumDiscount){
            int totDiscount = (totPrice*10)/100;  
            return totDiscount;      
        }
    }
    else if(getCustomer()->getType() == 'p'){
        for(auto article : articles){
            if(article->getType() == 't' && article->getStock() >= 4){
                diaT = article->getDiameter();  
            }
            if(article->getType() == 'r'){
                 diaR = article->getDiameter();
            }

            if(diaR == diaT){
                return (totPrice*10)/100;
            }
        }
    }

    return 0;
}

float Invoice::calculatePrice(){
    int sum=0;
    for(auto article : articles){
        sum += (article->getPrice()) * article->getStock();  //stock is used here to asing the amount of articles sold        
    }
    if(customer->getType() == 'c'){
        return sum;
    }
    else if(customer->getType()== 'p'){
        return sum + (sum * 21)/100;
    }
    return 0;
}
void Invoice::printInvoice(){
    std::cout << "\n-----Invoice-----" << "\n\n" << "Naam: " << getCustomer()->getName()
    << "\nArtikels: ";
    for(auto article : getArticles()){
        std::cout << "\n" << article->getStock() << " keer -> " <<article->getName(); //aantal nog bij zetten

    }
    std::cout << "\nTOTAAL: " << calculatePrice() << " euro"
        << "\nKorting " << calculateDiscount() << " euro";

        std::cout << "\nTotaal na korting: " << calculatePrice() - calculateDiscount() << " euro" << std::endl;
}