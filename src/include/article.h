#pragma once
#include <string>


class Article
{
    private:
        std::string name;
        std:: string manufacturer;
        int stock;
        int diameter;
        float price;
    protected:
        char type;
    public:
        Article(std::string name, std::string manufacturer,
        int stock, int diameter, float price, char type);
        virtual ~Article() = default;
        
        std::string getName();
        std::string getManufacturer();
        int getStock();
        int getDiameter();
        float getPrice();
        virtual char getType() =  0;

        void setName(std::string inputName);
        void setManufacturer(std::string inputManufacturer);
        void setStock(int inputStock);
        void setDiameter(int inputDiameter);
        void setPrice(float inputPrice);
        void setType(char inputType);
        void printArticle();
        virtual void print() = 0;
        virtual Article* makeCopy() = 0;

};