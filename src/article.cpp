#include <string>
#include "article.h"

std::string Article::getName(){
    return name;
}
std::string Article::getManufacturer(){
    return manufacturer;
}
int Article::getStock(){
    return stock;
}
int Article::getDiamter(){
    return diameter;
}
float Article::getPrice(){
    return price;
}
char Article::getType(){
    return type;
}

std::string Article::setName(std::string inputName){
    name = inputName;
}
std::string Article::setName(std::string inputManufacturer){
    manufacturer = inputManufacturer;
}
int Article::setStock(int inputStock){
    stock = inputStock;
}
int Article::setDiameter(int inputDiameter){
    diameter = inputDiameter;
}
float Article::setPrice(float inputPrice){
    price = inputPrice;
}
char Article::setType(char inputType){
    type = inputType;
}
