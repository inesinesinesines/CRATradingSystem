#include <string>
#include "MockDriver.cpp"
using std::string;

class AutoTradingSystem {
public:
	std::unique_ptr<StockBrockerDriver> brocker;
	string broker_name;

	bool selectStockBroker(std::string blockername) {
		if (blockername == "mock") {
			brocker = std::make_unique<MockDriver>();
			this->broker_name = "mock";
			return true;
		}

		if (blockername == "kiwer") {
			brocker = std::make_unique<Kiwer>();
			this->broker_name = "kiwer";
			return true;
		}

		if (blockername == "nemo") {
			brocker = std::make_unique<Nemo>();
			this->broker_name = "nemo";
			return true;
		}

		return false;

	};

	std::string getCurrentBrokerName() {
		return broker_name;
	}
};