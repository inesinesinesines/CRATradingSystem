#include "Brocker.h"
#include "MockDriver.h"
#include <string>
#include <iostream>
#include <memory> 


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


		//if (broker == "kiwer") {
		//	brocker = std::make_unique<Kiwer>();
		//	this->broker_name = "kiwer";
		//	return true;
		//}

		//if (broker == "nemo") {
		//	brocker = std::make_unique<Nemo>();
		//	this->broker_name = "nemo";
		//	return true;
		//}

		return false;

	};

	std::string getCurrentBrokerName() {
		return broker_name;
	}
};