#pragma once
#include <string>

class Customer{
    private:
        std::string name;
        std::string address;
        char type;
    public:
        Customer();
        ~Customer();
        std::string getName();
        std::string getAddress();
        char getType();
    
        std::string setName(std::string inputName);
        std::string setAddress(std::string inputAddress);
        char setType(char inputType);
};