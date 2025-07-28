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

  void checkAssert(std::string str) {
    if (str == "") {
      throw std::invalid_argument("Invalid Argument Exists");
    }
  }

 public:
  bool login(std::string id, std::string password) override {
    checkAssert(id);
    checkAssert(password);

    std::cout << "Login Success\n";
    isLogined = true;
    return true;
  }

  bool buy(std::string password, int count, int price) override {
    checkAssert(password);

    if (!isLoginState()) {
      return false;
    }

    std::cout << "Buy Success\n";
    return true;
  }

  bool sell(std::string code, int count, int stockPrice) override {
    checkAssert(code);

    if (!isLoginState()) {
      return false;
    }

    std::cout << "Sell Success\n";
    return true;
  };
  int getPrice(std::string code) override {
    checkAssert(code);

    if (!isLoginState()) {
      return 0;
    }

    return 1;
  };
};