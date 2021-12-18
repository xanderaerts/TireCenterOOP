#include "include/filehandeling.h"


void loadArticles(TireCenter &tirecenter){
    std::vector<Article*> articles;

    std::fstream ArticlesInFile{"src/data/articles.txt",std::ios::in};

    if(!ArticlesInFile){
        std::cerr << "File could not be opened" << std::endl;
        exit(EXIT_FAILURE);
    }

    std::vector<Article*> Articles;
    std::string line;
    int amountArt;

    getline(ArticlesInFile,line);
    amountArt = std::stoi(line);
    std::cout << "amount: " << amountArt << std::endl;
 
    for(int i = 0;i<amountArt;i++){

        getline(ArticlesInFile, line);

        if(line[0] == 't'){
            Tire* tire = new Tire();
            tire->setType('t');

            getline(ArticlesInFile,line);
            tire->setName(line);

            getline(ArticlesInFile,line);
            tire->setManufacturer(line);

            getline(ArticlesInFile,line);
            tire->setStock(std::stoi(line));

            getline(ArticlesInFile, line);
            tire->setDiameter(std::stoi(line));

            getline(ArticlesInFile, line);
            tire->setPrice(std::stof(line));

            getline(ArticlesInFile,line);
            tire->setWidth(std::stoi(line));

            getline(ArticlesInFile, line);
            tire->setHeight(std::stoi(line));

            getline(ArticlesInFile, line);
            tire->setSpeedIndex(line);

            getline(ArticlesInFile,line);
            tire->setSeason(line[0]);

            articles.push_back(tire);
        }
        else if(line[0] == 'r'){
            Rim* rim = new Rim();
            rim->setType('r');

            getline(ArticlesInFile,line);
            rim->setName(line);

            getline(ArticlesInFile,line);
            rim->setManufacturer(line);

            getline(ArticlesInFile,line);
            rim->setStock(std::stoi(line));

            getline(ArticlesInFile, line);
            rim->setDiameter(std::stoi(line));

            getline(ArticlesInFile, line);
            rim->setPrice(std::stof(line));

            getline(ArticlesInFile,line);
            rim->setAluminium(std::stoi(line));

            getline(ArticlesInFile,line);
            rim->setColor(line);

            getline(ArticlesInFile,line);
            rim->setWidth(std::stoi(line));
            articles.push_back(rim);

        }
    }


    tirecenter.setArticles(articles);
}