#include "include/customer.h"


Customer::Customer(){}


std::string Customer::getName(){
    return name;
}
std::string Customer::getAddress(){
    return address;
}
char Customer::getType(){
    return type;
}

void Customer::setName(std::string inputName){
    name = inputName;
}
void Customer::setAddress(std::string inputAddress){
    address = inputAddress;
}
void Customer::setType(char inputType){
    type = inputType;
}
