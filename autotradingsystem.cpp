#include <string>

#include "Broker.h"
#include "MockDriver.cpp"
#include "kiwer_adapter.cpp"
#include "nemo_adapter.cpp"

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
};