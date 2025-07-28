#include "kiwer_api.cpp"
#include "Broker.cpp"
#include <string>


class KiwerAdapter : public StockBrockerDriver {
public:
	KiwerAdapter(KiwerAPI* kiwer) : api(kiwer) {

	}

	bool login(std::string id, std::string passwd) override {
		api->login(id, passwd);
		return true;
	}

	bool buy(std::string code, int count, int price) override {
		api->buy(code, count, price);
	}

	bool sell(std::string code, int count, int price) override {
		api->sell(code, count, price);
	}

	int getPrice(std::string code) override {
		api->currentPrice(code);
	}

private:
	KiwerAPI* api;
};