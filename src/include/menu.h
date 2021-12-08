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
    searchInvoice,
    showStock
};

std::string UseCaseToString(Menu);
void printMenuUseCaseDetails(std::vector<Menu>);
