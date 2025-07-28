#include <string>

class StockBrockerDriver {
public:
    //virtual ~StockBrockerDriver() = default;

    virtual bool login(std::string id, std::string passwd) = 0;
    virtual bool buy(std::string code, int price, int quantity) = 0;
    virtual bool sell(std::string code, int price, int quantity) = 0;
    virtual int getPrice(std::string code) = 0;
};

