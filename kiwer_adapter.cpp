#pragma once
#include "kiwer_api.cpp"
#include "Broker.h"
#include <string>


class KiwerAdapter : public StockBrockerDriver {
public:
	KiwerAdapter() = default;
	KiwerAdapter(KiwerAPI* kiwer) : api(kiwer) {

	}

	bool login(std::string id, std::string passwd) override {
		api->login(id, passwd);
		return true;
	}

	bool buy(std::string code, int count, int price) override {
		api->buy(code, count, price);
		return true;
	}

	bool sell(std::string code, int count, int price) override {
		api->sell(code, count, price);
		return true;
	}

	int getPrice(std::string code) override {
		return api->currentPrice(code);
	}

private:
	KiwerAPI* api = nullptr;
};