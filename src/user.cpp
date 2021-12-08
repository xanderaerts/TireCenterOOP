#include <string>
#include "include/user.h"

std::string User::getUsername(){
    return username;
}

std::string User::getPassword(){
    return password;
}

std::string User::getRole(){
    return role;
}

void User::setUsername(std::string inputUsername){
    username = inputUsername;
}

void User::setPassword(std::string inputPassword){
    password = inputPassword;
}

void User::setRole(std::string inputRole){
    role = inputRole;
}


User::User(){
    password = "admin";
}


User::~User(){

}