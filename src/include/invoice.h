#pragma once 
#include <vector>
#include "customer.h"
#include "article.h"

class Invoice{
    private:
    Customer customer;
    std::vector<Article*> articles;
    float price;
    int discount;

    public:
        Invoice();
        ~Invoice();

        Customer getCustomer();
        void setCustomer(Customer);
        
        std::vector<Article*> getArticles();
        void setArticles(std::vector<Article*>);

        float getPrice();
        void setPrice(float);

        int getDiscount();
        void setDiscount(int);

        float calculateDiscount();
        float calculatePrice();

        


        


};
