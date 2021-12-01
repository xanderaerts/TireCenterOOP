#include <string>

#include "include/company.h"

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