#include <iostream>
#include <string>
#include "include/rim.h"
#include "include/article.h"


Rim::Rim(std::string name, std::string manufacturer,
        int stock, int diameter, float price, char type,
        int width, bool aluminium, std::string color)
    : Article(name, manufacturer, stock, diameter, price, type),
    width(width), aluminium(aluminium), color(color)
{
    
}

//Rim::~Rim(){}

//test

bool Rim::getAluminium(){
    return aluminium;
}
void Rim::setAluminium(bool inputAluminium){
    aluminium = inputAluminium;
}

std::string Rim::getColor(){
    return color;
}
void Rim::setColor(std::string inputColor){
    color = inputColor;
}

int Rim::getWidth(){
    return width;
}
void Rim::setWidth(int inputWidth){
    width = inputWidth;
}


char Rim::getType(){
    return type;
}