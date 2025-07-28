#include "nemo_api.cpp"
#include "Broker.cpp"
#include <string>


class NemoAdapter : public StockBrockerDriver {
public:
	NemoAdapter(NemoAPI* nemo) : api(nemo) {

	}

	bool login(std::string id, std::string passwd) override {
		api->certification(id, passwd);
		return true;
	}

	bool buy(std::string code, int count, int price) override {
		api->purchasingStock(code, price, count);
	}

	bool sell(std::string code, int count, int price) override {
		api->sellingStock(code, price, count);
	}

	int getPrice(std::string code) override {
		api->getMarketPrice(code, 1);
	}

private:
	NemoAPI* api;
};