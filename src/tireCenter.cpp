#include <vector>
#include <string>
#include "include/tireCenter.h"



TireCenter::TireCenter(){}

TireCenter::~TireCenter(){}

std::string TireCenter::getName(){
    return name;
}
std::string TireCenter::getAddress(){
    return address;
}
std::vector<Article*> TireCenter::getArticles(){
    return articles;
}
std::vector<Customer*> TireCenter::getCustomers(){
    return customers;
}

void TireCenter::setName(std::string inputName){
    name = inputName;
}
void TireCenter::setAddress(std::string inputAdress){
    address = inputAdress;
}
void TireCenter::setArticles(std::vector<Article*> inputArticle){
    articles = inputArticle;
    
}
void TireCenter::setCustomers(std::vector<Customer*> inputCustomer){
    customers = inputCustomer;
}

