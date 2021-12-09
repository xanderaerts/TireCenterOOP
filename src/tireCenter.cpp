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
std::vector<Article*>& TireCenter::getArticle(){s
    return articles;
}
std::vector<Customer*>& TireCenter::getCustomer(){
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
void TireCenter::setCustomer(std::vector<Customer*> inputCustomer){
    customers = inputCustomer;
}

