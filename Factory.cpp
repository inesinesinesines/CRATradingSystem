#pragma once
#include "Broker.h"
#include "MockDriver.cpp"
#include "kiwer_adapter.h"
#include "nemo_adapter.h"
#include <string>

class BrokerFactory {
public:
	static StockBrockerDriver* makeBroker(std::string brokername) {
		if (brokername == "mock") {
			return new MockDriver();
		}
		if (brokername == "kiwer") {
			return KiwerAdapter::getInstance(new KiwerAPI());
		}
		if (brokername == "nemo") {
			return NemoAdapter::getInstance(new NemoAPI());
		}
	}
};
