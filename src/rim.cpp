#include <iostream>
#include <string>
#include "include/rim.h"


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