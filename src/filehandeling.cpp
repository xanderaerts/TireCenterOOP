#include "include/filehandeling.h"


void loadArticles(TireCenter &tirecenter){
    std::vector<Article*> articles;
    std::string line;
    int amountArt;

    //std::fstream articlesInFile{"src/data/articles.txt",std::ios::in};
    std::fstream articlesInFile{"C:/Users/xande/OneDrive/AAE-ICT/2de_jaar/OOP/eindProject1Oop2021/src/data/articles.txt",std::ios::in};

    if(!articlesInFile){
        std::cerr << "Articles file could not be opened" << std::endl;
        exit(EXIT_FAILURE);
    }

    getline(articlesInFile,line);
    amountArt = std::stoi(line);
    //std::cout << "amount: " << amountArt << std::endl;
 
    for(int i = 0;i<amountArt;i++){

        getline(articlesInFile, line);

        if(line[0] == 't'){
            Tire* tire = new Tire();
            tire->setType('t');

            getline(articlesInFile,line);
            tire->setName(line);

            getline(articlesInFile,line);
            tire->setManufacturer(line);

            getline(articlesInFile,line);
            tire->setStock(std::stoi(line));

            getline(articlesInFile, line);
            tire->setDiameter(std::stoi(line));

            getline(articlesInFile, line);
            tire->setPrice(std::stof(line));

            getline(articlesInFile,line);
            tire->setWidth(std::stoi(line));

            getline(articlesInFile, line);
            tire->setHeight(std::stoi(line));

            getline(articlesInFile, line);
            tire->setSpeedIndex(line);

            getline(articlesInFile,line);
            tire->setSeason(line[0]);

            articles.push_back(tire);
        }
        else if(line[0] == 'r'){
            Rim* rim = new Rim();
            rim->setType('r');

            getline(articlesInFile,line);
            rim->setName(line);

            getline(articlesInFile,line);
            rim->setManufacturer(line);

            getline(articlesInFile,line);
            rim->setStock(std::stoi(line));

            getline(articlesInFile, line);
            rim->setDiameter(std::stoi(line));

            getline(articlesInFile, line);
            rim->setPrice(std::stof(line));

            getline(articlesInFile,line);
            rim->setAluminium(std::stoi(line));

            getline(articlesInFile,line);
            rim->setColor(line);

            getline(articlesInFile,line);
            rim->setWidth(std::stoi(line));
            articles.push_back(rim);

        }
    }

    tirecenter.setArticles(articles);
}

void loadCustomers(TireCenter &tirecenter){
    std::vector<Customer*> customers;
    int amountCust;
    std::string line;

    //std::fstream customersInFile{"src/data/customers.txt",std::ios::in};
    std::fstream customersInFile{"C:/Users/xande/OneDrive/AAE-ICT/2de_jaar/OOP/eindProject1Oop2021/src/data/customers.txt",std::ios::in};

    if(!customersInFile){
        std::cerr << "Customers file could not be opened" << std::endl;
        exit(EXIT_FAILURE);
    }

    getline(customersInFile,line);
    amountCust = std::stoi(line);

    for(int i = 0;i<amountCust;i++){
        getline(customersInFile,line);
        
        if(line[0] == 'p'){
            Customer* customer = new Customer();

            customer->setType('p');
            
            getline(customersInFile,line);
            customer->setName(line);

            getline(customersInFile,line);
            customer->setAddress(line);            
            
            customers.push_back(customer);
        }
        else if(line[0] == 'c'){
            Company* company = new Company();

            company->setType('c');

            getline(customersInFile,line);
            company->setName(line);

            getline(customersInFile,line);
            company->setAddress(line);

            getline(customersInFile,line);
            company->setVATNr(line);

            getline(customersInFile,line);
            company->setVolumeDiscount(std::stoi(line));

            customers.push_back(company);
        }
    }
    tirecenter.setCustomers(customers);
}

void loadInvoices(TireCenter &tirecenter){
    std::vector<Invoice*> invoices;
    std::string line;
    int amountInvoices,amountArt;

    
    //std::fstream invoicesInFile{"src/data/invoices.txt",std::ios::in};
    std::fstream invoicesInFile{"C:/Users/xande/OneDrive/AAE-ICT/2de_jaar/OOP/eindProject1Oop2021/src/data/invoices.txt",std::ios::in};

    if(!invoicesInFile){
        std::cerr << "Customers file could not be opened" << std::endl;
        exit(EXIT_FAILURE);
    }

    getline(invoicesInFile,line);
    amountInvoices = std::stoi(line);

    for(int i = 0;i<amountInvoices;i++){
        Invoice* invoice = new Invoice();

        getline(invoicesInFile,line);
        amountArt = std::stoi(line);

        getline(invoicesInFile,line);
        if(line[0] == 'p'){
            Customer* customer = new Customer();
            customer->setType('p');
            
            getline(invoicesInFile,line);
            customer->setName(line);

            getline(invoicesInFile,line);
            customer->setAddress(line);

            invoice->setCustomer(customer);
        }
        else if(line[0] == 'c'){
            Company* company = new Company();
            company->setType('c');

            getline(invoicesInFile,line);
            company->setName(line);

            getline(invoicesInFile,line);
            company->setAddress(line);

            getline(invoicesInFile,line);
            company->setVATNr(line);

            getline(invoicesInFile,line);
            company->setVolumeDiscount(std::stoi(line));

            invoice->setCustomer(company);
        }

        std::vector<Article*> articles;
       for(int i = 0;i<amountArt;i++){

            getline(invoicesInFile, line);

            if(line[0] == 't'){
                Tire* tire = new Tire();
                tire->setType('t');

                getline(invoicesInFile,line);
                tire->setName(line);

                getline(invoicesInFile,line);
                tire->setManufacturer(line);

                getline(invoicesInFile,line);
                tire->setStock(std::stoi(line));

                getline(invoicesInFile, line);
                tire->setDiameter(std::stoi(line));

                getline(invoicesInFile, line);
                tire->setPrice(std::stof(line));

                getline(invoicesInFile,line);
                tire->setWidth(std::stoi(line));

                getline(invoicesInFile, line);
                tire->setHeight(std::stoi(line));

                getline(invoicesInFile, line);
                tire->setSpeedIndex(line);

                getline(invoicesInFile,line);
                tire->setSeason(line[0]);

                articles.push_back(tire);
            }
            else if(line[0] == 'r'){
                Rim* rim = new Rim();
                rim->setType('r');

                getline(invoicesInFile,line);
                rim->setName(line);

                getline(invoicesInFile,line);
                rim->setManufacturer(line);

                getline(invoicesInFile,line);
                rim->setStock(std::stoi(line));

                getline(invoicesInFile, line);
                rim->setDiameter(std::stoi(line));

                getline(invoicesInFile, line);
                rim->setPrice(std::stof(line));

                getline(invoicesInFile,line);
                rim->setAluminium(std::stoi(line));

                getline(invoicesInFile,line);
                rim->setColor(line);

                getline(invoicesInFile,line);
                rim->setWidth(std::stoi(line));
                articles.push_back(rim);
            }
        }
        invoice->setArticles(articles);

       /* getline(invoicesInFile,line);
        invoice->setPrice(std::stof(line));*/
        
        getline(invoicesInFile,line);
        invoice->setDiscount(std::stoi(line));

        invoices.push_back(invoice);
    }

    tirecenter.setInvoices(invoices);

}
