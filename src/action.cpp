//here are all the function's declared
#include <iostream>
#include "include/actions.h"

std::vector<std::string> askNewArticleData(){
    std::vector<std::string> articleData;
    std::string input;
    std::string articleDataMembers[6] ={"naam","manufacturer","stock","diameter","price"};

    std::cout << "Geef de volgende gegevens van het artikel in: " << std::endl;
    
    for(int i=0;i<5;i++){        
        std::cout << articleDataMembers[i] << ": ";
        std::cin >> input;
        articleData.push_back(input);
    }

    return articleData;
}

std::vector<std::string> askNewTireData(){
    std::vector<std::string> TireData;
    std::string input;
    std::string articleDataMembers[4] ={"width","height","speedindex","season(only one char)"};

    std::cout << "Geef de volgende gegevens van de band in: " << std::endl;
    
    for(int i=0;i<4;i++){        
        std::cout << articleDataMembers[i] << ": ";
        std::cin >> input;
        TireData.push_back(input);
    }

    return TireData;
}

std::vector<std::string> askNewRimData(){
    std::vector<std::string> RimData;
    std::string input;
    std::string articleDataMembers[3] ={"aluminium","color","width"};

    std::cout << "Geef de volgende gegevens van de velg in: " << std::endl;
    
    for(int i=0;i<3;i++){        
        std::cout << articleDataMembers[i] << ": ";
        std::cin >> input;
        RimData.push_back(input);
    }

    return RimData;
}

void add_Article(TireCenter &tirecenter){
    char type;
    std::vector<std::string> ArticleData,TireData,RimData;

    do{
    std::cout << "Welk type of articel wil je toevoegen? (t/r)" << std::endl;
    std::cin >> type;
    }while(type != 'r' && type != 't');

    if(type == 't'){
        ArticleData = askNewArticleData();
        TireData = askNewTireData();
    }
    else if(type == 'r'){
        ArticleData = askNewArticleData();
        RimData = askNewRimData();
        curArticles = tirecenter.getArticles();
    }
}

