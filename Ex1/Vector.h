#pragma once
class Vector
{
public:
	Vector();
	~Vector();
	void printVector();
    void  makeVector(double** arr2D);
	double& operator[] (const int index);
	void operator++();
	void operator++(int);
	void operator--();
	void operator--(int);
private:
	const int size = 15;
	double* vector;
};

