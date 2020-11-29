#include "Vector.h"
#include<iostream>
#include<iomanip>
#include <cassert>

using namespace std;
Vector::Vector()
{
	vector = new double[size];
}
Vector::~Vector()
{
	delete[] vector;
}
void Vector::makeVector(double** arr2D)
{
	size_t k = 0;
	const size_t rows = 5;
	const size_t cols = 3;

	for (int i = rows - 1; i >= 0; i--)
	{
		for (size_t j = 0; j < cols; j++)
		{
			*(vector+k) = *(*(arr2D + i) + j);
			k++;
		}
	}
}
void Vector::printVector()
{
	for (size_t i = 0; i < size; i++)
	{
		cout << *(vector + i) << setw(14);
	}
	cout << endl;
}
double& Vector::operator[] (const int index)
{
	assert(index >= 0 && index < size);
		return *(vector + index);
}
void Vector:: operator++()
{
	for (size_t i = 0; i < size; i++)
	{
		++* (vector + i);
	}
}
void Vector:: operator++(int)
{
	for (size_t i = 0; i < size; i++)
	{
		(* (vector + i))++;
	}
}
void Vector:: operator--()
{
	for (size_t i = 0; i < size; i++)
	{
		--*(vector + i);
	}
}
void Vector:: operator--(int)
{
	for (size_t i = 0; i < size; i++)
	{
		(* (vector + i))--;
	}
}