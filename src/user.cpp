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


std::string User::setUsername(std::string inputUsername){
    username = inputUsername;
}

std::string User::setPassword(std::string inputPassword){
    password = inputPassword;
}

std::string User::setRole(std::string inputRole){
    role = inputRole;
}

bool User::setStatus(bool inputStatus){
    status = inputStatus;
}