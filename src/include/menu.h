#pragma once
#include <vector>
#include <string>

enum Menu{
    addOrder=1,
    searchArtcle,
    addArticle,
    rmArticle,
    editArticle,
    addCust,
    searchCust,
    editCust,
    addInvoice,
    searchInvoice
};

std::string toString(Menu);
void printMenu2(std::vector<Menu>);
