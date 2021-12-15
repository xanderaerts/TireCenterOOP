#pragma once
#include <string>
#include <iostream>

class Customer
{
    private:
        std::string name;
        std::string address;
        char type;
    public:
        Customer(std::string name,std::string address,char type);
        Customer();
        virtual ~Customer() = default;

        std::string getName();
        std::string getAddress();
        char getType();
    
        void setName(std::string inputName);
        void setAddress(std::string inputAddress);
        void setType(char inputType);

        void printCustomer();
        virtual Customer* makecopy();
};