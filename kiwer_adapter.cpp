#include "kiwer_api.cpp"
#include <string>


class KiwerAdapter {
public:
	KiwerAdapter(KiwerAPI* kiwer) : api(kiwer) {

	}

	bool login(std::string id, std::string passwd) {
		api->login(id, passwd);
		return true;
	}

	bool buy(std::string code, int count, int price) {
		api->buy(code, count, price);
	}

	bool sell(std::string code, int count, int price) {
		api->sell(code, count, price);
	}

	bool getPrice(std::string code, int count, int price) {
		api->currentPrice(code);
	}

private:
	KiwerAPI* api;
};