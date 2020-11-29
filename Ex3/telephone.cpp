#include "telephone.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
 
using namespace std;

Telephone::Phone()
{
	 model = "model";
	 number = "000 000 00 00";
	 Balance = 10.0;
}
Phone::Phone( std::string strModel,  std::string strNumber, float valBalance)
{
	model = strModel;
	number = strNumber;
	Balance = valBalance;
}
void Phone::setModel(std::string strModel)
{
	model = strModel;
}
void Phone::setNumber(std::string strNumber)
{
	number = strNumber;
}
void Phone::setBalance(float valBalance)
{
	Balance = valBalance;
}
void Phone::serialize()
{
	ofstream file("data.txt");
	file << model << "\t" << number << "\t" << lastDialed << "\t" << Balance << "\n";
	file.close();
}
void Phone::deserialize()
{
	ifstream file("data.txt");
	string line;
	if (!file.is_open())
	{
		cout << "Error";
	}
	else
	{
		while (getline(file, line))
		{
			string token;
			int i = 0;
			istringstream iss(line);
			while (getline(iss, token, '\t')) {
				if (i == 0) model = token;
				if (i == 1) number = token;
				if (i == 2) lastDialed = token;
				if (i == 3) Balance = atoi(token.c_str());//перевод string в int
				i++;
			}
		}
	}
	file.close();
}
void Phone::serialize(const std::string& filename) 
{
	ofstream file(filename);
	file << model << "\t" << number << "\t" << lastDialed << "\t" << Balance << "\n";
	file.close();
}
void Phone::deserialize(const std::string& filename)
{
	ifstream file(filename);
	string line;
	if (!file.is_open())
	{
		cout << "Error";
	}
	else
	{
		while (getline(file, line))
		{
			istringstream iss(line);
			string token;
			int i = 0;
			while (getline(iss, token, '\t'))
			{
				if (i == 0) model = token;
				if (i == 1) number = token;
				if (i == 2) lastDialed = token;
				if (i == 3) Balance = atoi(token.c_str());//перевод string в int
				i++;
			}
		}
	}

	file.close();
}
void Phone::call(const std::string toNumber)
{
	lastDialed = toNumber;
	int minute = (int)(rand() % 30) + 1;  
	Balance = Balance - minute * 0.5;
}
void Phone::printInfo()
{
	cout << "Phone Number:\nModel: " << model << "\tNumber: " << number << "\tLast_call: " << lastDialed << "\tBalance:" << Balance << endl;
}
std::string Phone::getNumber() 
{
	return number;
}