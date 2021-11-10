#include <customer.h>

std::string Customer::getName(){
    return name;
}
std::string Customer::getAddress(){
    return address;
}
char Customer::getType(){
    return type;
}

std::string Customer::setName(std::string inputName){
    name = inputName;
}
std::string Customer::setAddress(std::string inputAddress){
    address = inputAddress;
}
char Customer::setType(char inputType){
    type = inputType;
}
