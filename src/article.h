#include <string>
class Article{
    private:
        std::string name;
        std:: string manufacturer;
        int stock;
        int diameter;
        float price;
        char type;
    public:
        std::string getName();
        std::string getManufacturer();
        int getStock();
        int getDiamter();
        float getPrice();
        char getType();

        std::string setName(std::string inputName);
        std::string setManufacturer(std::string inputManufacturer);
        int setStock(int inputStock);
        int setDiameter(int inputDiameter);
        float setPrice(float inputPrice);
        char setType(char inputType);


    Article();
    ~Article();
};