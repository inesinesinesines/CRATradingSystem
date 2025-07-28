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

  void checkArgumentValidation(std::string argument) {
    if (argument == "") {
      throw std::invalid_argument("Invalid Argument Exists");
    }
  }

 public:
  bool login(std::string id, std::string password) override {
    checkArgumentValidation(id);
    checkArgumentValidation(password);

    std::cout << "Login Success\n";
    isLogined = true;
    return true;
  }

  bool buy(std::string password, int count, int price) override {
    checkArgumentValidation(password);

    if (!isLoginState()) {
      return false;
    }

    std::cout << "Buy Success\n";
    return true;
  }

  bool sell(std::string code, int count, int stockPrice) override {
    checkArgumentValidation(code);

    if (!isLoginState()) {
      return false;
    }

    std::cout << "Sell Success\n";
    return true;
  };
  int getPrice(std::string code) override {
    checkArgumentValidation(code);

    if (!isLoginState()) {
      return 0;
    }

    return 1;
  };
};