#include <string>

#include "Broker.h"
#include "MockDriver.h"

using std::string;

class AutoTradingSystem {
public:

	string broker_name;

	void selectStockBroker(std::string blockername) {

	}

	std::string getCurrentBrokerName() {
		return broker_name;
	}
};