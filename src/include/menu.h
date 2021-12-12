#pragma once
#include <vector>
#include <string>
#include "article.h"
#include "actions.h"

enum Menu{
    addOrder=1,
    searchArtcle,
    addArticle,
    rmArticle,
    editArticle,
    addCust,
    searchCust,
    editCust,
    searchInvoice
};

std::string UseCaseToString(Menu);
void printMenuUseCaseDetails(std::vector<Menu>,TireCenter &tirecenter);
