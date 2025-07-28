#include "nemo_api.cpp"
#include "Broker.h"
#include <string>


class NemoAdapter : public StockBrockerDriver {
public:

	NemoAdapter() = default;
	NemoAdapter(NemoAPI* nemo) : api(nemo) {

	}

	bool login(std::string id, std::string passwd) override {
		api->certification(id, passwd);
		return true;
	}

	bool buy(std::string code, int count, int price) override {
		api->purchasingStock(code, price, count);
		return true;
	}

	bool sell(std::string code, int count, int price) override {
		api->sellingStock(code, price, count);
		return true;
	}

	int getPrice(std::string code) override {
		return api->getMarketPrice(code, 0);
	}

private:
	NemoAPI* api = nullptr;
};