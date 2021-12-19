#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "tireCenter.h"
#include "tire.h"
#include "rim.h"
#include "article.h"
#include "customer.h"
#include "company.h"
#include "invoice.h"
#include "actions.h"

void loadArticles(TireCenter &tirecenter);
void loadCustomers(TireCenter &tirecenter);
void loadInvoices(TireCenter &tirecenter);