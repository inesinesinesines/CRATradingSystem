#include "gmock/gmock.h"
#include <string>

///#include "MockDriver.cpp"

class StockBrockerDriver {
public:
	virtual bool login(std::string id, std::string pwd);
	virtual bool buy(std::string code, int stockCount, int stockPrice);
	virtual bool sell(std::string code, int stockCount, int stockPrice);
	virtual int getPrice(std::string code);
};

class MockDriver : public StockBrockerDriver {
public:
	bool login(std::string id, std::string pwd) override { return true; };
	bool buy(std::string code, int stockCount, int stockPrice)override { return true; };
	bool sell(std::string code, int count, int stockPrice)override { return true; };
	int getPrice(std::string code) override { return 1; };
};


class MockDriverTest : public ::testing::Test {
public:
	void SetUp() override {
		StockBrockerDriver* sbDriver = new MockDriver();
	}
	StockBrockerDriver* sbDriver;

	const std::string ID = "USER";
	const std::string PASSWORD = "PASSWORD";
	const std::string STOCKCODE = "SAM";
	const int stockCount = 1000;
	const int stockPrice = 50;
};

TEST_F(MockDriverTest, LoginTest_1) {
	EXPECT_NO_THROW({ sbDriver->login(ID, PASSWORD); });
}

TEST_F(MockDriverTest, BuyTest) {
	// User should login before request buy 
	EXPECT_EQ(false, sbDriver->buy(STOCKCODE, stockCount, stockPrice));

	sbDriver->login(ID, PASSWORD);
	EXPECT_EQ(true, sbDriver->buy(STOCKCODE, stockCount, stockPrice));
}

TEST_F(MockDriverTest, SellTest) {
	// User should login before request sell 
	EXPECT_EQ(false, sbDriver->sell(STOCKCODE, stockCount, stockPrice));

	sbDriver->login(ID, PASSWORD);
	EXPECT_EQ(true, sbDriver->sell(STOCKCODE, stockCount, stockPrice));
}

TEST_F(MockDriverTest, GetPrice) {
	// User should login before request getPrice 
	EXPECT_EQ(false, sbDriver->getPrice(STOCKCODE));

	sbDriver->login(ID, PASSWORD);
	EXPECT_EQ(true, sbDriver->getPrice(STOCKCODE));
}

