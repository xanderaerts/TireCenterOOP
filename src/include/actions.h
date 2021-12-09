// all the funcion declarations of the use case's are in this file
#include <vector>
#include <string>
#include "tireCenter.h"
#include "article.h"
#include "tire.h"
#include "rim.h"

std::vector<std::string> askNewArticleData();//asks the data that is the same for both articles
std::vector<std::string> askNewTireData();
std::vector<std::string> askNewRimData();
void add_Article(TireCenter &tirecenter);