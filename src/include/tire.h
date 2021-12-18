#pragma once
#include <string>
#include "article.h"


class Tire :
    public Article
{
    private:
        int width;
        int height;
        std::string speedIndex;
        char season;

    public:
        Tire(std::string name, std::string manufacturer,
        int stock, int diameter, float price, char type,
        int width, int height, std::string speedIndex, char season);
        virtual ~Tire()= default;

        Tire();
        
        int getWidth();
        void setWidth(int);

        int getHeight();
        void setHeight(int);

        std::string getSpeedIndex() ;
        void setSpeedIndex(std::string);

        char getSeason();
        void setSeason(char);

        virtual char getType();

        virtual void print();
        virtual Article* makeCopy();
};