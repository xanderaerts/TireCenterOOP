#pragma once
#include <string>
#include <vector>
#include "customer.h"
#include "article.h"
#include "invoice.h"

class TireCenter{
    private:
        std::string name;
        std::string address;
        std::vector<Article*> articles;
        std::vector<Customer*> customers;
        std::vector<Invoice*> invoices;
    public:
        TireCenter();
        ~TireCenter();

        std::string getName();
        std::string getAddress();
        std::vector<Article*> getArticles();
        std::vector<Customer*> getCustomers();
        std::vector<Invoice*> getInvoices();

        void setName(std::string inputName);
        void setAddress(std::string inputAddress);
        void setArticles(std::vector<Article*> inputArticle);
        void setCustomers(std::vector<Customer*> inputCustomer);
        void setInvoices(std::vector<Invoice*>inputInvoice);
};
