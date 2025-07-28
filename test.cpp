#include "gmock/gmock.h"
#include <string>
#if 0
#include "MockDriver.cpp"

class MockDriverTest : public ::testing::Test {
public:
protected:
	void SetUp() override {
	}

	StockBrockerDriver* sbDriver = new MockDriver();

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
	EXPECT_NO_THROW({ sbDriver->getPrice(STOCKCODE); });
}
#endif 