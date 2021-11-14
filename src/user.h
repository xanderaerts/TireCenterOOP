#pragma once
#include <string>

class User{
    private:
        std::string username;
        std::string password;
        std::string role;
        bool status;
    public:
        User(){
            username = "admin";
            password = "admin";
            role = "admin";
            status = 0;
        }
        std::string getUsername();
        std::string getPassword();
        std::string getRole();
        bool getStatus();

        std::string setUsername(std::string inputUsername);
        std::string setPassword(std::string inputPassword);
        std::string setRole(std::string inputRole);
        bool setStatus(bool satus);
};