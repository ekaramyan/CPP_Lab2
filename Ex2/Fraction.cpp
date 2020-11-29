#include "Fraction.h"
#include <string>
#include <sstream>
#include<iostream>
#include<cmath>
using namespace std;

Fraction::Fraction()
{
	x = 1;
	y = 1;
	cnt++;
}

Fraction::Fraction(string fractionStr)
{
	string token;
	int i = 0;
	istringstream iss(fractionStr);
	while (getline(iss, token, '/'))
	{
		if (i == 0) x = atoi(token.c_str());
		if (i == 1) y = atoi(token.c_str());
		i++;
	}
	if (y == 0)
	{
		cout << "Error";
		x,y = 1;
	}
	else
	cnt++;
}


Fraction::~Fraction()
{

}

Fraction Fraction:: operator+(const Fraction& secondFraction)
{
	Fraction res;
	if (this->y == secondFraction.y)
	{
		res.y = this->y;
		res.x = this->x + secondFraction.x;
	}
	else
	{
		res.y = this->y * secondFraction.y;
		res.x = this->x * secondFraction.y + secondFraction.x * this->y;
	}
	return res;
}
Fraction Fraction:: operator-(const Fraction& secondFraction)
{
	Fraction res;
	if (this->y == secondFraction.y)
	{
		res.y = this->y;
		res.x = this->x - secondFraction.x;
	}
	else
	{
		res.y = this->y * secondFraction.y;
		res.x = this->x * secondFraction.y - secondFraction.x * this->y;
	}
	return res;
}
Fraction Fraction:: operator*(const Fraction& secondFraction)
{
	Fraction res;
	res.x = this->x * secondFraction.x;
	res.y = this->y * secondFraction.y;
	return res;

}
Fraction Fraction:: operator/(const Fraction& secondFraction)
{
	Fraction res;
	res.x = this->x * secondFraction.y;
	res.y = this->y * secondFraction.x;
	return res;

}

void Fraction::reduce()
{
	int gcd = this->gcd(x, y);
	x = x / gcd;
	y = y / gcd;
}
void Fraction::printFraction()
{
	cout << x << "/" << y << endl;
}
int Fraction::getCnt()
{
	return cnt;
}

int Fraction::gcd(int n, int m)
{
	while (n != m) {
		if (n > m) {
			int tmp = n;
			n = m;
			m = tmp;
		}
		m = m - n;
	}
	return n;
}
void Fraction::printAsFraction(double decimal_fraction)
{
	Fraction fract;
	//
	string token;
	string fractStr = to_string( decimal_fraction);
	int i = 0;
	string yStr;
	istringstream iss(fractStr);
	while (getline(iss, token, ','))
	{
		if (i == 1)
			yStr = token;
		i++;
	}
	//
	fract.x = decimal_fraction * pow(10, yStr.size());
	fract.y = pow(10, yStr.size());
	fract.reduce();
	fract.printFraction();
}
void Fraction::printAsFraction(char* decimal_fraction)
{
	Fraction fract;
	string token;
	int i = 0;
	int x, y;
	string yStr;
	istringstream iss(decimal_fraction);
	while (getline(iss, token, '.'))
	{
		if (i == 0) x = atoi(token.c_str());
		if (i == 1)
		{
			y = atoi(token.c_str());
			yStr = token;
		}
		i++;
	}

	fract.y = pow(10, yStr.size());
	fract.x = fract.y * x + y;
	if (fract.y == 0)
	{
		cout << "Error";
		fract.x, fract.y = 1;
	}
	fract.reduce();
	fract.printFraction();
}