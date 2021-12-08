#include <string>
#include "include/article.h"

Article::Article(std::string name, std::string manufacturer,
    int stock, int diameter, float price, char type)
    
    : name(name), manufacturer(manufacturer), stock(stock), diameter(diameter),
    price(price), type(type)
{
    
}

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
/*char Article::getType(){
    return type;
}*/

void Article::setName(std::string inputName){
    name = inputName;
}
void Article::setManufacturer(std::string inputManufacturer) {
    manufacturer = inputManufacturer;
}
void Article::setStock(int inputStock){
    stock = inputStock;
}
void Article::setDiameter(int inputDiameter){
    diameter = inputDiameter;
}
void Article::setPrice(float inputPrice){
    price = inputPrice;
}
void Article::setType(char inputType){
    type = inputType;
}
