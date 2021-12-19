#pragma once
#include <vector>
#include <string>
#include "article.h"
#include "actions.h"
#include "user.h"
#include "filehandeling.h"

enum Menu{
    addOrder=1,
    searchArticle,
    addArticle,
    rmArticle,
    editArticle,
    addCust,
    searchCust,
    editCust,
    deleteCust,
    checkInvoice,
    goBack
};

std::string UseCaseToString(Menu);
void printMenuUseCase(TireCenter &tirecenter,User user);
void printMenuUseCaseDetails(std::vector<Menu>,TireCenter &tirecenter,User user);
