#include <string>
#include "include/tire.h"


Tire::Tire(std::string name, std::string manufacturer,
        int stock, int diameter, float price, char type,
        //Tire specific
        int width, int height, std::string speedIndex, char season)
        
    : Article(name, manufacturer, stock, diameter, price, type),
    width(width), height(height), speedIndex(speedIndex), season(season)
{
}

int Tire::getWidth(){
    return width;
}
void Tire::setWidth(int inputWidth){
    width = inputWidth;
}

int Tire::getHeight(){
    return height;
}
void Tire::setHeight(int inputHeight){
    height = inputHeight;
}

std::string Tire::getSpeedIndex(){
    return speedIndex;
}
void Tire::setSpeedIndex(std::string inputSpeedIndex){
    speedIndex = inputSpeedIndex;
}

char Tire::getSeason(){
    return season;
}
void Tire::setSeason(char inputSeason){
    season = inputSeason;
}

char Tire::getType(){
    return type;
}