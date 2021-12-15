#pragma once
#include <vector>
#include <string>
#include "article.h"
#include "actions.h"
#include "user.h"

enum Menu{
    addOrder=1,
    searchArtcle,
    addArticle,
    rmArticle,
    editArticle,
    addCust,
    searchCust,
    editCust,
    deleteCust,
    searchInvoice,
    goBack
};

std::string UseCaseToString(Menu);
void printMenuUseCase(TireCenter &tirecenter,User user);
void printMenuUseCaseDetails(std::vector<Menu>,TireCenter &tirecenter,User user);
