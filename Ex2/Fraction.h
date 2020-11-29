#pragma once
#include <string>
using namespace std;
class Fraction
{
public:
	Fraction();
	Fraction(string fractionStr);
	~Fraction();
	Fraction operator+(const Fraction& secondFraction);
	Fraction operator-(const Fraction& secondFraction);
	Fraction operator*(const Fraction& secondFraction);
	Fraction operator/(const Fraction& secondFraction);

	void reduce();
	void printFraction();

	static int getCnt();
	static int gcd(int n, int m);
	static void printAsFraction(double decimal_fraction);
	static void printAsFraction(char* decimal_fraction);

private:
	int x;
	int y;
	static int cnt;
};

