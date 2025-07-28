#pragma once
#include <string>
#include <iostream>
#include <memory>
#include "Broker.h"

class AutoTradingSystem : public StockBrockerDriver {
public:

    std::string broker_name;
    std::unique_ptr<StockBrockerDriver> brocker;
    void selectStockBroker(std::string blockername) {

    }

    std::string getCurrentBrokerName() {
        return ""; // nullptr ��� "" (std::string�� nullptr ��ȯ ����)
    }

    // StockBrockerDriver�� pure virtual �Լ� �ݵ�� ��� �����ؾ� ��!
    bool login(std::string id, std::string passwd) override {
        if (isValidLoginParameter(id, passwd)) {
            brocker->login(id, passwd);
            return true;
        }
        return false;
    }
    bool isValidLoginParameter(std::string& id, std::string& passwd)
    {
        if (brocker == nullptr) return false;
        if (id == "" || passwd == "") return false;
       
        return true;
    }
    bool buy(std::string code, int price, int quantity) override {
        return true;
    }
    bool sell(std::string code, int price, int quantity) override {
        return true;
    }
    int getPrice(std::string code) override {
        return 0;
    }
};