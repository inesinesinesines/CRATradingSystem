#include "Broker.cpp"
#include "gmock/gmock.h"

class MockDriver : public StockBrockerDriver {
 private:
  bool isLogined = false;
  bool isLoginState() {
    if (!isLogined) {
      std::cout << "Not Logined Yet\n";
      return false;
    }
    return true;
  }

 public:
  bool login(std::string id, std::string passwd) override {
    if (id == "" || passwd == "") {
      throw std::invalid_argument("Invalid Argument Exists");
    }
    std::cout << "Login Success\n";
    isLogined = true;
    return true;
  }

  bool buy(std::string password, int count, int price) override {
    if (!isLoginState()) {
      return false;
    }

    std::cout << "Buy Success\n";
    return true;
  }

  bool sell(std::string code, int count, int stockPrice) override {
    if (!isLoginState()) {
      return false;
    }

    std::cout << "Sell Success\n";
    return true;
  };
  int getPrice(std::string code) override {
    if (!isLoginState()) {
      return 0;
    }

    int price = std::rand() % 10 * 100 + 5000;
    return price;
  };
};