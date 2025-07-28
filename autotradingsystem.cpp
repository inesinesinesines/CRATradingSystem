#include <string>

#include "Broker.h"
#include "MockDriver.cpp"

using std::string;

class AutoTradingSystem {
public:

	std::unique_ptr<StockBrockerDriver> brocker;
	string broker_name;

	bool selectStockBroker(std::string brocker_name) {
		if (brocker_name == "mock") {
			brocker = std::make_unique<MockDriver>();
			this->broker_name = "mock";
			return true;
		}

		return false;

	}

	std::string getCurrentBrokerName() {
		return broker_name;
	}
};