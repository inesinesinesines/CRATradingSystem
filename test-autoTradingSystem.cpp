#include "gmock/gmock.h"
#include <string>

using namespace std;
using namespace testing;

//class AutoTradingSystem {
//public:
//	bool selectBroker(string broker) { return true; }
//	string getBrokerName() { return ""; };
//	void login(std::string id, std::string password) {};
//	string getLoginUserID() { return ""; };
//	void buy(std::string stockCode, int count, int price) {};
//	void sell(std::string stockCode, int count, int price) {};
//	int getPrice(std::string stockCode) { return 100; };
//	void buyNiceTiming(std::string stockCode, int cost) {};
//	void sellNiceTiming(std::string stockCode, int stockAmount) {};
//	int getUserStockCount(std::string stockCode) { return 0; /*user stock*/ };
//};

class AutoTradingSystemFixture : public Test{
public:
	AutoTradingSystem ats;
	const std::string BROKER = "DUMMY";
	const std::string ID = "USER";
	const std::string PASSWORD = "PASSWORD";
	const std::string STOCKCODE = "SAM";
	const int stockCount = 1000;
	const int stockPrice = 50;
};

TEST_F(AutoTradingSystemFixture, SelectBroker) {
	EXPECT_EQ(true, ats.selectBroker(BROKER));
}

TEST_F(AutoTradingSystemFixture, GetBroker) {
	ats.selectBroker(BROKER);
	EXPECT_EQ(BROKER, ats.getBrokerName());
}

TEST_F(AutoTradingSystemFixture, Login) {
	ats.selectBroker(BROKER);
	ats.login(ID, PASSWORD);
	EXPECT_EQ(ID, ats.getLoginUserID());
}

TEST_F(AutoTradingSystemFixture, LoginFailTest_NoBroker) {
	EXPECT_THROW(ats.login(ID, PASSWORD); , std::exception);
}

TEST_F(AutoTradingSystemFixture, Buy) {
	ats.selectBroker(BROKER);
	ats.login(ID, PASSWORD);
	int currentStockCount = ats.getUserStockCount(STOCKCODE);
	ats.buy(STOCKCODE, stockCount, stockPrice);
	EXPECT_EQ(currentStockCount + stockCount, ats.getUserStockCount(STOCKCODE));
}

TEST_F(AutoTradingSystemFixture, BuyFailTest_NoLogin) {
	ats.selectBroker(BROKER);
	EXPECT_THROW(ats.buy(STOCKCODE, stockCount, stockPrice), std::exception);
}

TEST_F(AutoTradingSystemFixture, BuyFailTest_StockCountMinus) {
	ats.selectBroker(BROKER);
	EXPECT_THROW(ats.buy(STOCKCODE, -100, stockPrice), std::exception);
}

TEST_F(AutoTradingSystemFixture, BuyFailTest_StockPriceMinus) {
	ats.selectBroker(BROKER);
	EXPECT_THROW(ats.buy(STOCKCODE, stockCount, -100), std::exception);
}

TEST_F(AutoTradingSystemFixture, Sell) {
	ats.selectBroker(BROKER);
	ats.login(ID, PASSWORD);
	ats.buy(STOCKCODE, stockCount, stockPrice);
	ats.sell(STOCKCODE, stockCount, stockPrice);
}

TEST_F(AutoTradingSystemFixture, SellFailTest_NoLogin) {
	ats.selectBroker(BROKER);
	EXPECT_THROW(ats.sell(STOCKCODE, stockCount, stockPrice), std::exception);
}

TEST_F(AutoTradingSystemFixture, SellFailTest_StockCountMinus) {
	ats.selectBroker(BROKER);
	EXPECT_THROW(ats.sell(STOCKCODE, -100, stockPrice), std::exception);
}

TEST_F(AutoTradingSystemFixture, SellFailTest_StockPriceMinus) {
	ats.selectBroker(BROKER);
	EXPECT_THROW(ats.sell(STOCKCODE, stockCount, -100), std::exception);
}

TEST_F(AutoTradingSystemFixture, GetPrice) {
	ats.selectBroker(BROKER);
	ats.login(ID, PASSWORD);
	EXPECT_NO_THROW(ats.getPrice(STOCKCODE));
}
