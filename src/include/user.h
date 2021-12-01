#pragma once
#include <string>

class User{
    private:
        std::string username;
        std::string password;
        std::string role;
    public:
        User(){
            password = "admin";
        }
        ~User();

        std::string getUsername();
        std::string getPassword();
        std::string getRole();
        bool getStatus();

        void setUsername(std::string inputUsername);
        void setPassword(std::string inputPassword);
        void setRole(std::string inputRole);
};