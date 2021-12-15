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

        Rim(std::string name, std::string manufacturer,
            int stock, int diameter, float price, char type,
            //Rim specific
            bool aluminium, std::string color,int width);
        virtual ~Rim() = default;

        bool getAluminium();
        void setAluminium(bool);

        std::string getColor();
        void setColor(std::string);

        int getWidth();
        void setWidth(int);

        virtual char getType();

        virtual void print();
        virtual Article* makeCopy();
};