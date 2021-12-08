#include <iostream>
#include "include/invoice.h"


Invoice::Invoice(){}
Invoice::~Invoice(){}



Customer Invoice::getCustomer(){
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

void Invoice::setCustomer(Customer inputCustomer){
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
    //
    return 0;
}