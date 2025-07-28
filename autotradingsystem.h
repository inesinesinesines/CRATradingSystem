#include <string>
// #include <memory>  // unique_ptr 사용 시 필요
// #include "StockBrockerDriver.h"  // 주석 처리된 부분 사용 시 필요

class AutoTradingSystem {
public:
    std::string broker_name;
    // std::unique_ptr<StockBrockerDriver> broker;

    bool selectStockBroker(std::string broker_name);

    std::string getCurrentBrokerName();
};
