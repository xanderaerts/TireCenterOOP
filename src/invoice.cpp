#include <iostream>
#include "include/invoice.h"


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
    //
    return 0;
}

float Invoice::calculatePrice(){
    int sum=0;
    for(auto article : articles){
        sum += (article->getPrice()) * article->getStock();  //stock is used here to asing the amount of articles sold        
    }
    return sum;
}
void Invoice::printInvoice(){
    std::cout << "-----Invoice-----" << "\n\n" << "Naam: " << getCustomer()->getName()
    << "Artikels: ";
    for(auto article : getArticles()){
        std::cout << "\n" << article->getName() << std::endl //aantal nog bij zetten
        << "TOTAAL:" << calculatePrice()
        << "Korting" << calculateDiscount()
        << "Totaal na korting: " << calculatePrice() - calculateDiscount() << std::endl;

    }
}