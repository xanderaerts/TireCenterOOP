#pragma once
#include <string>

class Customer
{
    private:
        std::string name;
        std::string address;
        char type;
    public:
        Customer(std::string name,std::string address,char type);
        virtual ~Customer() = default;

        std::string getName();
        std::string getAddress();
        char getType();
    
        void setName(std::string inputName);
        void setAddress(std::string inputAddress);
        void setType(char inputType);
};