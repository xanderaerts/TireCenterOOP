#include <string>
#include <iostream>
#include "include/tire.h"


Tire::Tire(std::string name, std::string manufacturer,
        int stock, int diameter, float price, char type,
        int width, int height, std::string speedIndex, char season)
        
    : Article(name, manufacturer, stock, diameter, price, type),
    width(width), height(height), speedIndex(speedIndex), season(season)
{
}

Tire::Tire() {}

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

    void Tire::print(){
            Article::printArticle();

            std::cout << "\nwidth: " << getWidth()
            << "\nHeight: " << getHeight()
            << "\nSpeedindex: " << getSpeedIndex()
            << "\nseason: " << getSeason() << std::endl;;
}


Article* Tire::makeCopy(){
    Article* newTire = new Tire(*this);
    return newTire;
}