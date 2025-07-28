#include "Broker.cpp"
#include "gmock/gmock.h"

class MockDriver : public Broker {
	MOCK_METHOD((bool), login, (std::string, std::string), (override));
	MOCK_METHOD((bool), buy, (std::string, int, int), (override));
	MOCK_METHOD((bool), sell, (std::string, int, int), (override));
	MOCK_METHOD((int), getPrice, (std::string), (override));
};