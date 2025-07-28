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

class AutoTradingSystemFixture : public TestWithParam<string> {
public:
	AutoTradingSystem ats;
	std::string BROKER = "";
	const std::string ID = "USER";
	const std::string PASSWORD = "PASSWORD";
	const std::string STOCKCODE = "SAM";
	const int stockCount = 1000;
	const int stockPrice = 50;

	void SetUp() override {
		std::ostringstream oss;
		oldCoutStreamBuf = std::cout.rdbuf();
		std::cout.rdbuf(oss.rdbuf()); // 새로운 버퍼로 redirection

		BROKER = GetParam();
	}

	void TearDown() override{
		std::cout.rdbuf(oldCoutStreamBuf); //복원
	}

	string GetConsolePrint() {
		return oss.str();
	}

private : 
	std::ostringstream oss;
	std::streambuf* oldCoutStreamBuf;
};


INSTANTIATE_TEST_SUITE_P(SelectBroker, AutoTradingSystemFixture, Values("mock", "kiwer", "nemo"));

TEST_P(AutoTradingSystemFixture, SelectBroker) {
	EXPECT_EQ(true, ats.selectBroker(BROKER));
}

TEST_P(AutoTradingSystemFixture, GetBroker) {
	ats.selectBroker(BROKER);
	EXPECT_EQ(BROKER, ats.getBrokerName());
}

TEST_P(AutoTradingSystemFixture, Login) {
	ats.selectBroker(BROKER);
	ats.login(ID, PASSWORD);
	EXPECT_EQ(ID, ats.getLoginUserID());
}

TEST_P(AutoTradingSystemFixture, LoginFailTest_NoBroker) {
	EXPECT_THROW(ats.login(ID, PASSWORD); , std::exception);
}

TEST_P(AutoTradingSystemFixture, Buy) {
	ats.selectBroker(BROKER);
	ats.login(ID, PASSWORD);
	int currentStockCount = ats.getUserStockCount(STOCKCODE);
	ats.buy(STOCKCODE, stockCount, stockPrice);
	EXPECT_EQ(currentStockCount + stockCount, ats.getUserStockCount(STOCKCODE));
}

TEST_P(AutoTradingSystemFixture, BuyFailTest_NoLogin) {
	ats.selectBroker(BROKER);
	EXPECT_THROW(ats.buy(STOCKCODE, stockCount, stockPrice), std::exception);
}

TEST_P(AutoTradingSystemFixture, BuyFailTest_StockCountMinus) {
	ats.selectBroker(BROKER);
	EXPECT_THROW(ats.buy(STOCKCODE, -100, stockPrice), std::exception);
}

TEST_P(AutoTradingSystemFixture, BuyFailTest_StockPriceMinus) {
	ats.selectBroker(BROKER);
	EXPECT_THROW(ats.buy(STOCKCODE, stockCount, -100), std::exception);
}

TEST_P(AutoTradingSystemFixture, Sell) {
	ats.selectBroker(BROKER);
	ats.login(ID, PASSWORD);
	ats.buy(STOCKCODE, stockCount, stockPrice);
	ats.sell(STOCKCODE, stockCount, stockPrice);
}

TEST_P(AutoTradingSystemFixture, SellFailTest_NoLogin) {
	ats.selectBroker(BROKER);
	EXPECT_THROW(ats.sell(STOCKCODE, stockCount, stockPrice), std::exception);
}

TEST_P(AutoTradingSystemFixture, SellFailTest_StockCountMinus) {
	ats.selectBroker(BROKER);
	EXPECT_THROW(ats.sell(STOCKCODE, -100, stockPrice), std::exception);
}

TEST_P(AutoTradingSystemFixture, SellFailTest_StockPriceMinus) {
	ats.selectBroker(BROKER);
	EXPECT_THROW(ats.sell(STOCKCODE, stockCount, -100), std::exception);
}

TEST_P(AutoTradingSystemFixture, GetPrice) {
	ats.selectBroker(BROKER);
	ats.login(ID, PASSWORD);
	EXPECT_NO_THROW(ats.getPrice(STOCKCODE));
}

TEST_P(AutoTradingSystemFixture, buyNiceTiming) {
	ats.selectBroker(BROKER);
	ats.login(ID, PASSWORD);

	int prevUserStockCnt = ats.getUserStockCount(STOCKCODE);
	ats.buyNiceTiming(STOCKCODE, stockCount * stockPrice);
	EXPECT_THAT(ats.getUserStockCount(STOCKCODE), Ge(prevUserStockCnt));
}

TEST_P(AutoTradingSystemFixture, buyNiceTiming_FailWith0Cost) {
	ats.selectBroker(BROKER);
	ats.login(ID, PASSWORD);

	int prevUserStockCnt = ats.getUserStockCount(STOCKCODE);
	EXPECT_THROW(ats.buyNiceTiming(STOCKCODE, 0), std::exception);
}

TEST_P(AutoTradingSystemFixture, sellNiceTiming) {
	ats.selectBroker(BROKER);
	ats.login(ID, PASSWORD);

	int prevUserStockCnt = ats.getUserStockCount(STOCKCODE);
	ats.sellNiceTiming(STOCKCODE, stockCount * stockPrice);
	EXPECT_THAT(ats.getUserStockCount(STOCKCODE), Le(prevUserStockCnt));
}

TEST_P(AutoTradingSystemFixture, sellNiceTiming_FailWith0Cost) {
	ats.selectBroker(BROKER);
	ats.login(ID, PASSWORD);

	int prevUserStockCnt = ats.getUserStockCount(STOCKCODE);
	EXPECT_THROW(ats.sellNiceTiming(STOCKCODE, 0), std::exception);
}