#include "nemo_api.cpp"
#include <string>


class NemoAdapter {
public:
	NemoAdapter(NemoAPI* nemo) : api(nemo) {

	}

	bool login(std::string id, std::string passwd) {
		api->certification(id, passwd);
		return true;
	}

	bool buy(std::string code, int count, int price) {
		api->purchasingStock(code, price, count);
	}

	bool sell(std::string code, int count, int price) {
		api->sellingStock(code, price, count);
	}

	bool getPrice(std::string code, int count, int price) {
		api->getMarketPrice(code, 1);
	}

private:
	NemoAPI* api;
};