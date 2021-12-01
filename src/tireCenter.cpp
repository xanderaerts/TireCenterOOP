#include <vector>
#include <string>
#include "include/tireCenter.h"

std::string tireCenter::getName(){
    return name;
}
std::string tireCenter::getAddress(){
    return address;
}
std::vector<Article> tireCenter::getArticle(){
    return articles;
}
std::vector<Customer> tireCenter::getCustomer(){
    return customers;
}

void tireCenter::setName(std::string inputName){
    name = inputName;
}
void tireCenter::setAddress(std::string inputAdress){
    address = inputAdress;
}
void tireCenter::setArticle(std::vector<Article> inputArticle){
    articles = inputArticle;
    
}
void tireCenter::setCustomer(std::vector<Customer> inputCustomer){
    customers = inputCustomer;
}
