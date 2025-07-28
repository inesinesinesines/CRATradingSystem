#include "gmock/gmock.h"
#include <string>
#include <cctype>
using namespace std;
using namespace testing;

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
		std::cout.rdbuf(oss.rdbuf()); // »õ·Î¿î ¹öÆÛ·Î redirection

		BROKER = GetParam();
	}

	void TearDown() override{
		std::cout.rdbuf(oldCoutStreamBuf); //º¹¿ø
	}
	string GetConsolePrintlower() {
		string originalStr = oss.str();
		string lowerStr;
		for (char c : originalStr) {
			lowerStr += static_cast<char>(tolower(c));
		}
		return lowerStr;
	}

	void SetBrokerAndLogin() {
		ats.selectBroker(BROKER);
		ats.login(ID, PASSWORD);
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
	SetBrokerAndLogin();
  
	EXPECT_EQ(ID, ats.getLoginUserID());
	string str = GetConsolePrintlower();
	EXPECT_THAT(str.find("login"), Not(std::string::npos));
}

TEST_P(AutoTradingSystemFixture, LoginFailTest_NoBroker) {
	EXPECT_THROW(ats.login(ID, PASSWORD); , std::exception);
}

TEST_P(AutoTradingSystemFixture, Buy) {
	SetBrokerAndLogin();
	int currentStockCount = ats.getUserStockCount(STOCKCODE);
	ats.buy(STOCKCODE, stockCount, stockPrice);
	EXPECT_EQ(currentStockCount + stockCount, ats.getUserStockCount(STOCKCODE));
	string str = GetConsolePrintlower();
	EXPECT_THAT(str.find("buy"), Not(std::string::npos));
}

TEST_P(AutoTradingSystemFixture, BuyFailTest_NoLogin) {
	ats.selectBroker(BROKER);
	EXPECT_THROW(ats.buy(STOCKCODE, stockCount, stockPrice), std::exception);
}

TEST_P(AutoTradingSystemFixture, BuyFailTest_StockCountMinus) {
	SetBrokerAndLogin();
	EXPECT_THROW(ats.buy(STOCKCODE, -100, stockPrice), std::exception);
}

TEST_P(AutoTradingSystemFixture, BuyFailTest_StockPriceMinus) {
	SetBrokerAndLogin();
	EXPECT_THROW(ats.buy(STOCKCODE, stockCount, -100), std::exception);
}

TEST_P(AutoTradingSystemFixture, Sell) {
	SetBrokerAndLogin();

	ats.buy(STOCKCODE, stockCount, stockPrice);
	int prevUserStockCnt = ats.getUserStockCount(STOCKCODE);
	ats.sell(STOCKCODE, stockCount, stockPrice);
	EXPECT_THAT(ats.getUserStockCount(STOCKCODE), Le(prevUserStockCnt));

	string str = GetConsolePrintlower();
	EXPECT_THAT(str.find("sell"), Not(std::string::npos));
}

TEST_P(AutoTradingSystemFixture, SellFailTest_NoLogin) {
	ats.selectBroker(BROKER);
	EXPECT_THROW(ats.sell(STOCKCODE, stockCount, stockPrice), std::exception);
}

TEST_P(AutoTradingSystemFixture, SellFailTest_StockCountMinus) {
	SetBrokerAndLogin();
	EXPECT_THROW(ats.sell(STOCKCODE, -100, stockPrice), std::exception);
}

TEST_P(AutoTradingSystemFixture, SellFailTest_StockPriceMinus) {
	SetBrokerAndLogin();
	EXPECT_THROW(ats.sell(STOCKCODE, stockCount, -100), std::exception);
}

TEST_P(AutoTradingSystemFixture, GetPrice) {
	SetBrokerAndLogin();
	EXPECT_NO_THROW(ats.getPrice(STOCKCODE));
}

TEST_P(AutoTradingSystemFixture, buyNiceTiming) {
	SetBrokerAndLogin();
	int prevUserStockCnt = ats.getUserStockCount(STOCKCODE);
	ats.buyNiceTiming(STOCKCODE, stockCount * stockPrice);
	EXPECT_THAT(ats.getUserStockCount(STOCKCODE), Ge(prevUserStockCnt));
}

TEST_P(AutoTradingSystemFixture, buyNiceTiming_FailWith0Cost) {
	SetBrokerAndLogin();
	int prevUserStockCnt = ats.getUserStockCount(STOCKCODE);
	EXPECT_THROW(ats.buyNiceTiming(STOCKCODE, 0), std::exception);
}

TEST_P(AutoTradingSystemFixture, sellNiceTiming) {
	SetBrokerAndLogin();
	int prevUserStockCnt = ats.getUserStockCount(STOCKCODE);
	ats.sellNiceTiming(STOCKCODE, stockCount * stockPrice);
	EXPECT_THAT(ats.getUserStockCount(STOCKCODE), Le(prevUserStockCnt));
}

TEST_P(AutoTradingSystemFixture, sellNiceTiming_FailWith0Cost) {
	SetBrokerAndLogin();
	int prevUserStockCnt = ats.getUserStockCount(STOCKCODE);
	EXPECT_THROW(ats.sellNiceTiming(STOCKCODE, 0), std::exception);
}