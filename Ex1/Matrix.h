#pragma once
class Matrix
{
public:
	Matrix();
	~Matrix();
	void printMatrix();
	void initializeMatrix();
	double at(int i, int j);
	void setAt(int i, int j, double val);
	void operator++ ();
	void operator++ (int);
	void operator-- ();
	void operator-- (int);
	double** getMatrix();
private:
	const size_t rows = 5;
	const size_t cols = 3;
	double** matrix; 
};

