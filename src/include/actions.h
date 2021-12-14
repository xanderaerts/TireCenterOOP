// all the funcion declarations of the use case's are in this file
#include <vector>
#include <string>
#include "tireCenter.h"
#include "article.h"
#include "tire.h"
#include "rim.h"
#include "customer.h"
#include "company.h"


//all use cases for articles
void add_Article(TireCenter &tirecenter);
int search_Article(TireCenter &tirecenter,bool);
Article* filterTires(std::vector<Article*> articles,bool);
Article* filterRims(std::vector<Article*> articles,bool);
Article* filterSize(std::vector<Article*> articles,bool);
void delete_Articles(TireCenter &tirecenter);
void edit_Article(TireCenter &tirecenter);

//all use cases for customers
void add_Customer(TireCenter &tirecenter);
int search_Customer(TireCenter &tirecenter);
void filter_Private(TireCenter &tirecenter);
void filter_Company(TireCenter &tirecenter);
int filter_Customer_Name(TireCenter &tirecenter);
void edit_Customer(TireCenter &tirecenter);




