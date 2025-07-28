#include "gmock/gmock.h"
#include <string>

TEST(TC, TC1) {
	AutoTradingSystem* ats = new AutoTradingSystem();
	std::string broker = "mock"
	ats->selectStockBroker(broker);
	EXPECT_EQ(broker, ats->getCurrentBrokerName());
}
