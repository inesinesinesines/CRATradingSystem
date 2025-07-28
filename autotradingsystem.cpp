#include <string>
//#include "MockDriver.h"

class AutoTradingSystem {
public:

	std::string broker_name;

	bool selectStockBroker(std::string brocker_name) {

		if (brocker_name == "mock") {
			//std::make_unique<MockDriver>();
			this->broker_name = "mock";
			return true;
		}
		return false;

	}

	std::string getCurrentBrokerName() {
		return broker_name;
	}
};