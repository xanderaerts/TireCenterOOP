#include <iostream>
#include "invoice.h"

Customer Invoice::getCustomer(){
    return customer;
}
std::vector<Article> Invoice::getArticles(){
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
void Invoice::setArticles(std::vector<Article> inputArticles){
    articles = inputArticles;
}
void Invoice::setPrice(float inputPrice){
    price = inputPrice;
}
void Invoice::setDiscount(int inputDiscount{
    discount = inputDiscount;
}

float Invoice::calculateDiscount(){
    //
}

float Invoice::calculatePrice(){
    //
}