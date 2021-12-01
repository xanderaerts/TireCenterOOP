#include <string>
#include "include/tire.h"

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
    return speedindex;
}
void Tire::setSpeedIndex(std::string inputSpeedIndex){
    speedindex = inputSpeedIndex;
}

char Tire::getSeason(){
    return season;
}
void Tire::setSeason(char inputSeason){
    season = inputSeason;
}