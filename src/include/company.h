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

    Company();
    ~Company();

    std::string getVATNr();
    void setVATNr(std::string);

    int getVolumeDiscount();
    void setVolumeDiscount(int);
};