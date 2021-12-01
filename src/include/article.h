#pragma once
#include <string>
class Article{
    private:
        std::string name;
        std:: string manufacturer;
        int stock;
        int diameter;
        float price;
        char type;
    public:
        Article();
        virtual ~Article() = default;
        std::string getName();
        std::string getManufacturer();
        int getStock();
        int getDiamter();
        float getPrice();
        char getType();

        void setName(std::string inputName);
        void setManufacturer(std::string inputManufacturer);
        void setStock(int inputStock);
        void setDiameter(int inputDiameter);
        void setPrice(float inputPrice);
        void setType(char inputType);
};