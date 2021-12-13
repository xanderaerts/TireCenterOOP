#pragma once
#include "customer.h"
#include <string>

class Company
    : public Customer
{
    private:
    std::string VATNr;
    int volumeDiscount;

    public:

    Company(std::string name,std::string address,char type,std::string VATNr,int volumeDiscount);
    virtual ~Company() = default ;

    std::string getVATNr();
    void setVATNr(std::string);

    int getVolumeDiscount();
    void setVolumeDiscount(int);
};