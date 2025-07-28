#include <string>

class AutoTradingSystem {
public:
    std::string broker_name;
    // std::unique_ptr<StockBrockerDriver> broker;

    bool selectStockBroker(std::string broker_name);

    std::string getCurrentBrokerName();
};