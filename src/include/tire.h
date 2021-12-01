#pragma once
#include <string>
#include "article.h"


class Tire :
    public Article
{
    private:
        int width;
        int height;
        std::string speedindex;
        char season;
    public:
        Tire();
        ~Tire();
        
        int getWidth();
        void setWidth(int);

        int getHeight();
        void setHeight(int);

        std::string getSpeedIndex() ;
        void setSpeedIndex(std::string);

        char getSeason();
        void setSeason(char);
};