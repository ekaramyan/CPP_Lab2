#pragma once
#include <string>
class Telephone
{
public:
	Telephone();
	Telephone( std::string strModel,  std::string strNumber, float valBalance);
	std::string getNumber();
	void setModel(std::string strModel);
	void setNumber(std::string strNumber);
	void setBalance(float valBalance);
	void serialize();
	void deserialize();
	void serialize(const std::string& filename);
	void deserialize(const std::string& filename);
	void call(const std::string toNumber);
	void printInfo();
private:
	 std::string model;
	std::string number;
	std::string lastDialed;
	float Balance;
};