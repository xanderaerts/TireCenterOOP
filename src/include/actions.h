// all the funcion declarations of the use case's are in this file
#include <vector>
#include <string>
#include "tireCenter.h"
#include "article.h"
#include "tire.h"
#include "rim.h"


void add_Article(TireCenter &tirecenter);

int search_Article(TireCenter &tirecenter,bool);
Article* filterTires(std::vector<Article*> articles,bool);
Article* filterRims(std::vector<Article*> articles,bool);
Article* filterSize(std::vector<Article*> articles,bool);

void delete_Articles(TireCenter &tirecenter);
