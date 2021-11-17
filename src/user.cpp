#include <string>
#include "user.h"

std::string User::getUsername(){
    return username;
}

std::string User::getPassword(){
    return password;
}

std::string User::getRole(){
    return role;
}

bool User::getStatus(){
    return status;

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

void User::setStatus(bool inputStatus){
    status = inputStatus;
}