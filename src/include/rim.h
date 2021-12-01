#pragma once
#include <string>
#include "article.h"


class Rim:
    public Article
{
    private:
        bool aluminium;
        std::string color;
        int width;
    public:

        Rim();
        ~Rim();

        bool getAluminium();
        void setAluminium(bool);

        std::string getColor();
        void setColor(std::string);

        int getWidth();
        void setWidth(int);

};