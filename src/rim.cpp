#include <iostream>
#include <string>
#include "include/rim.h"
//#include "include/article.h"


Rim::Rim(std::string name, std::string manufacturer,
        int stock, int diameter, float price, char type,
         bool aluminium, std::string color,int width)
    : Article (name, manufacturer, stock, diameter, price, type),
     aluminium(aluminium), color(color),width(width)
{
    
}

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

void Rim::print(){
            Article::printArticle();

            std::cout << "\naluminium: " << getAluminium()
            << "\ncolor: " << getColor()
            << "\nwidth: " << getWidth() << std::endl;
}

Article* Rim::makeCopy(){
    Article* newRim = new Rim(*this);
    return newRim;
}