#include <string>

class User{
    private:
        std::string username;
        std::string password;
        std::string role;
    public:
        std::string getName();
        std::string getPassword;
        std::string getRole;

        std::string setName();
        std::string setPassword();
        std::string setRole();
};