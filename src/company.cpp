#include <string>

#include "include/company.h"


Company::Company(std::string name, std::string address,char type,
        std::string VATNr, int volumeDiscount)
    : Customer(name, address, type), VATNr(VATNr), volumeDiscount(volumeDiscount)
{
    
}


//Company::~Company(){}

std::string Company::getVATNr(){
    return VATNr;
}
void Company::setVATNr(std::string inputVATNr){
    VATNr = inputVATNr;
}

int Company::getVolumeDiscount(){
    return volumeDiscount;
}
void Company::setVolumeDiscount(int inputVolumeDiscount){
    volumeDiscount = inputVolumeDiscount;
}

void Company::printCompany(){
    Customer::printCustomer();
    std::cout << "\nBTW NR: " << getVATNr() << "\nKorting: " << getVolumeDiscount() << std::endl;
}