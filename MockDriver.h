#ifndef MOCKDRIVER_H
#define MOCKDRIVER_H

#include <string>
#include <iostream>
#include <stdexcept>
#include "Broker.h"

class MockDriver : public StockBrockerDriver {
private:
    bool isLogined = false;

    bool isLoginState();

    void checkArgumentValidation(std::string argument);

public:
    bool login(std::string id, std::string password) override;

    bool buy(std::string code, int count, int price) override;

    bool sell(std::string code, int count, int stockPrice) override;

    int getPrice(std::string code) override;
};

#endif // MOCKDRIVER_H
