#include <string>

class Broker {
public:
	virtual bool login(std::string id, std::string passwd) = 0;
	virtual bool buy(int code, int price, int quantity) = 0;
	virtual bool sell(int code, int price, int quantity) = 0;
	virtual int getPrice() = 0;
};