#pragma once
#include <string>
#include <vector>
#include "customer.h"
#include "article.h"

class TireCenter{
    private:
        std::string name;
        std::string address;
        std::vector<Article*> articles;
        std::vector<Customer*> customers;
    public:
        TireCenter();
        ~TireCenter();

        std::string getName();
        std::string getAddress();
        std::vector<Article*>& getArticle();
        std::vector<Customer*>& getCustomer();

        void setName(std::string inputName);
        void setAddress(std::string inputAddress);
        void setArticle(std::vector<Article*> inputArticle);
        void setCustomer(std::vector<Customer*> inputCustomer);
};