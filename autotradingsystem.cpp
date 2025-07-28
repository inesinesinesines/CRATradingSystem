#pragma once

#include "Broker.h"
#include "MockDriver.cpp"
#include "kiwer_adapter.cpp"
#include "nemo_adapter.cpp"

using std::string;

class AutoTradingSystem : public StockBrockerDriver{
public:

	std::unique_ptr<StockBrockerDriver> brocker;
	string broker_name;

	bool selectStockBroker(std::string brocker_name) {
		if (brocker_name == "mock") {
			brocker = std::make_unique<MockDriver>();
			this->broker_name = "mock";
			return true;
		}
		if (brocker_name == "kiwer") {
			brocker = std::make_unique<KiwerAdapter>();
			this->broker_name = "kiwer";
			return true;
		}
		if (brocker_name == "nemo") {
			brocker = std::make_unique<NemoAdapter>();
			this->broker_name = "nemo";
			return true;
		}

		return false;
    }

    std::string getCurrentBrokerName() {
        return broker_name;
    }

    // StockBrockerDriver의 pure virtual 함수 반드시 모두 구현해야 함!
    bool login(std::string id, std::string passwd) override {
        if (isValidLoginParameter(id, passwd)) {
            brocker->login(id, passwd);
            return true;
        }
        return false;
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

private:
    bool isValidLoginParameter(std::string& id, std::string& passwd)
    {
        if (brocker == nullptr) return false;
        if (id == "" || passwd == "") return false;

        return true;
    }
};