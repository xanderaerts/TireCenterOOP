#include <vector>
#include <string>
#include "tireCenter.h"
#include "customer.h"
#include "article.h"


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

std::string tireCenter::setName(std::string inputName){
    name = inputName;
}
std::string tireCenter::setAddress(std::string inputAdress){
    address = inputAdress;
}
std::vector<Article> tireCenter::setArticle(std::vector<Article> inputArticle){
    articles = inputArticle;
    
}
std::vector<Customer> tireCenter::setCustomer(std::vector<Customer> inputCustomer){
    customers = inputCustomer;
}
