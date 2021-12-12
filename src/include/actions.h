// all the funcion declarations of the use case's are in this file
#include <vector>
#include <string>
#include "tireCenter.h"
#include "article.h"
#include "tire.h"
#include "rim.h"


void add_Article(TireCenter &tirecenter);
Article* search_Article(TireCenter &tirecenter);
Article* filterTires(std::vector<Article*> articles);
Article* filterRims(std::vector<Article*> articles);
Article* filterSize(std::vector<Article*> articles);
