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
            password = "admin";
            status = 0;
        }
        std::string getUsername();
        std::string getPassword();
        std::string getRole();
        bool getStatus();

        void setUsername(std::string inputUsername);
        void setPassword(std::string inputPassword);
        void setRole(std::string inputRole);
        void setStatus(bool satus);
};