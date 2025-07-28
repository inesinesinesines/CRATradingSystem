#include "gmock/gmock.h"
#include "autotradingsystem.cpp"
#include "MockDriver.cpp"
#include <string>

TEST(TC, TC1) {
	AutoTradingSystem* ats = new AutoTradingSystem();
	std::string broker = "mock";
	ats->selectStockBroker(broker);
	EXPECT_EQ(broker, ats->getCurrentBrokerName());
}


TEST(MockDriverTest, LoginTest) {
	StockBrockerDriver* sbDriver = new MockDriver();
	std::string ID = "USER";
	std::string PASSWORD = "PASSWORD";	
	std::string STOCKCODE = "SAM";
	EXPECT_NO_THROW({ sbDriver->login(ID, PASSWORD); });
}

TEST(MockDriverTest, BuyTest) {
	StockBrockerDriver* sbDriver = new MockDriver();
	std::string ID = "USER";
	std::string PASSWORD = "PASSWORD";
	std::string STOCKCODE = "SAM";
	int count = 1000;
	int price = 50;

	// User should login before request buy 
	EXPECT_EQ(false, sbDriver->buy(PASSWORD, count, price));

	sbDriver->login(ID, PASSWORD);
	EXPECT_EQ(true, sbDriver->buy(PASSWORD, count, price));
}

TEST(MockDriverTest, SellTest) {
	StockBrockerDriver* sbDriver = new MockDriver();
	std::string ID = "USER";
	std::string PASSWORD = "PASSWORD";
	std::string STOCKCODE = "SAM";
	int count = 1000;
	int price = 50;

	// User should login before request buy 
	EXPECT_EQ(false, sbDriver->sell(PASSWORD, count, price));

	sbDriver->login(ID, PASSWORD);
	EXPECT_EQ(true, sbDriver->sell(PASSWORD, count, price));
}

TEST(MockDriverTest, GetPrice) {
	StockBrockerDriver* sbDriver = new MockDriver();
	std::string ID = "USER";
	std::string PASSWORD = "PASSWORD";
	std::string STOCKCODE = "SAM";
	int count = 1000;
	int price = 50;

	// User should login before request buy 
	EXPECT_EQ(false, sbDriver->getPrice(PASSWORD, count, price));

	sbDriver->login(ID, PASSWORD);
	EXPECT_EQ(true, sbDriver->getPrice(PASSWORD, count, price));
}

