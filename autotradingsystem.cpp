#include "Brocker.h"
#include "MockDriver.h"
#include <string>
<<<<<<< HEAD
#include <memory>
#include "Broker.h"
//#include "MockDriver.h"

class AutoTradingSystem {
public:

	std::string broker_name;
	std::unique_ptr<StockBrockerDriver> brocker;

	bool selectStockBroker(std::string brocker_name) {

		if (brocker_name == "mock") {
			//std::make_unique<MockDriver>();
			this->broker_name = "mock";
			return true;
		}
		return false;
=======
#include <iostream>
#include <memory> 


using std::string;

class AutoTradingSystem {
public:
	std::unique_ptr<StockBrockerDriver> brocker;
	string broker_name;
>>>>>>> ea288d175d600b8279afbada0089214db8730987


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