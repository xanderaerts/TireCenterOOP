#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include "include/user.h"
#include "include/menu.h"
#include "include/tireCenter.h"
#include "include/tire.h"

void authenticateUser();
void printMenuUseCase();

User user;
TireCenter tirecenter;

int main(){
    int choice = 0;
    int logged = 0;
    
    std::vector<Article*> articles;
    articles.push_back(new Tire("test","coolemaker",100,10,20,'t',20,10,"FWAGEG",'w'));
    articles.push_back(new Tire("test1","test",100,10,20,'t',20,10,"FWAGEG",'w'));
    articles.push_back(new Tire("test2","test",100,10,20,'t',20,10,"FWAGEG",'w'));
    articles.push_back(new Tire("test3","test",100,10,20,'t',20,10,"kfdhqk",'w'));
    tirecenter.setArticles(articles);

    std::vector<Customer*> customers;
    customers.push_back(new Customer("lotte","grasheide",'p'));
    customers.push_back(new Company("faxie","bonheiden",'c',"BE04456",5));
    tirecenter.setCustomers(customers);


    do{
        if(logged == 1){
            printMenuUseCase();
        }
        
        std::cout << "-----Login-----" << std::endl;
        std::cout << "\t1.Manager" << std::endl;
        std::cout << "\t2.Werknemer" << std::endl;
        std::cout << "\t3.Logout" << std::endl;
        std::cout << "Maak een keuze: ";
        std::cin >> choice;
        switch(choice){
            case 1:
                /*naar file schrijven welke activce user is ofzo iets we vinden wel iets*/
                user.setRole("admin");
                authenticateUser();
                logged = 1;
                break;
            case 2:
                user.setRole("worker");
                authenticateUser();
                logged = 1;
                break;
            case 3:
                std::cout << "Tot ziens!" << std::endl;
                logged = 0;
                break;
            default:
                std::cout <<"\n\nKies een juiste optie! [1-3]" << std::endl;
                break;
        }

    }while(choice != 3);
    return 0;
}

void authenticateUser(){
    int attemps=0;
    std::string inputPass="",inputUsername;

    while(attemps < 4 && inputPass != user.getPassword()){
        std::cout << "Username: ";
        std::cin >> inputUsername;
        std::cout << "Passwoord: ";
        std::cin >> inputPass;
        attemps++;
        if(inputPass != user.getPassword()){
            std::cout << "Het passwoord was niet correct." << std::endl;
        }

        if(inputPass == user.getPassword()){
            user.setUsername(inputUsername);
            printMenuUseCase();
        }
        else if(attemps > 3){
            std::cout << "Toegang geweigerd, te veel pogingen!" << std:: endl;
            exit(-1);
        }
    }    
}

void printMenuUseCase(){
    int choiceUseCaseGroup=-1;

    std::cout << "\n\n";
    std::cout << "Welkom " << user.getUsername() << std::endl;
    std::cout << "--------------" << std::endl;
    
    while(choiceUseCaseGroup<0 || choiceUseCaseGroup > 3){

        std::cout << "\t1.Bestellingen" << std::endl;    
        std::cout << "\t2.Artikels (zoeken/voorraad)" << std::endl;
        std::cout << "\t3.Klantenbeheer" << std::endl;
        //std::cout << "\t4.Facturatie" << std::endl;
        std::cout << "Maak een keuze: ";
        std::cin >> choiceUseCaseGroup;

        switch(choiceUseCaseGroup){
            case 1:
                if(user.getRole() == "admin"){
                    std::vector<Menu> UseCaseFunctions{addOrder,searchInvoice};
                    printMenuUseCaseDetails(UseCaseFunctions,tirecenter);
                }
                else if(user.getRole() == "worker"){
                    std::vector<Menu> UseCaseFunctions{addOrder,searchInvoice};
                    printMenuUseCaseDetails(UseCaseFunctions,tirecenter);
                }
                break;
            case 2:
                if(user.getRole() == "admin"){
                    std::vector<Menu> UseCaseFunctions{searchArtcle,addArticle,rmArticle,editArticle};
                    printMenuUseCaseDetails(UseCaseFunctions,tirecenter);
                }
                else if(user.getRole() == "worker"){
                    std::vector<Menu> UseCaseFunctions{searchArtcle,editArticle};
                    printMenuUseCaseDetails(UseCaseFunctions,tirecenter);
                }    
                break;
            
            case 3:
                if(user.getRole() == "admin"){
                    std::vector<Menu> UseCaseFunctions{addCust,searchCust,editCust};
                    printMenuUseCaseDetails(UseCaseFunctions,tirecenter);
                }
                else if(user.getRole() == "worker"){
                    std::vector<Menu> UseCaseFunctions{addCust,searchCust};
                    printMenuUseCaseDetails(UseCaseFunctions,tirecenter);
                }
                break;
            
           /* case 4:
                if(user.getRole() == "admin"){
                    std::vector<Menu> UseCaseFunctions{addInvoice,searchInvoice};
                    printMenuUseCaseDetails(UseCaseFunctions,tirecenter);
                }
                else if(user.getRole() == "worker"){
                    std::vector<Menu> UseCaseFunctions{searchInvoice,addInvoice};
                    printMenuUseCaseDetails(UseCaseFunctions,tirecenter);
                }
                break;*/
            default:
            std::cout << "\nMaak een geldige keuze!"<<std::endl;
                continue;
        }
    }
}