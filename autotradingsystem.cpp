#include <string>

#pragma once

#include "Broker.h"
#include "MockDriver.cpp"
#include "kiwer_adapter.h"
#include "nemo_adapter.h"
#include "Factory.cpp"

using std::string;


class AutoTradingSystem {
public:

	StockBrockerDriver *brocker;
	string broker_name;

	bool selectStockBroker(std::string brocker_name) {
		brocker = BrokerFactory::makeBroker(brocker_name);
		this->broker_name = brocker_name;

		return false;
	}

	std::string getCurrentBrokerName() {
		return broker_name;
	}
};