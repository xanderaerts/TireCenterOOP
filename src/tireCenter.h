#pragma once
#include <string>
#include <vector>
#include "customer.h"
#include "article.h"

class tireCenter{
    private:
        std::string name;
        std::string address;
        std::vector<Article> articles;
        std::vector<Customer> customers;
    public:
        tireCenter();
        ~tireCenter();
        std::string getName();
        std::string getAddress();
        std::vector<Article> getArticle();
        std::vector<Customer> getCustomer();

        std::string setName(std::string inputName);
        std::string setAddress(std::string inputAddress);
        std::vector<Article> setArticle(std::vector<Article> inputArticle);
        std::vector<Customer> setCustomer(std::vector<Customer> inputCustomer);
};