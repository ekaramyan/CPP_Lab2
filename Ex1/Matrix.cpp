#include "Matrix.h"
#include <iostream>
#include<iomanip>
using namespace std;

Matrix::Matrix()
{
	matrix = new double* [rows];
	for (size_t i = 0; i < rows; i++)
	{
		*(matrix + i) = new double[cols];
	}
}
Matrix::~Matrix()
{
	for (size_t i = 0; i < rows; i++)
	{
		delete[] * (matrix + i);
	}
	delete[] matrix;
}
void Matrix::printMatrix()
{
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			cout << setw(14) << *(*(matrix + i) + j);
		}
		cout << endl;
	}
	cout << endl;
}
void Matrix::initializeMatrix()
{
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			*(*(matrix + i) + j) = sin(i - j) + cos(i + j);
		}
	}
}
double Matrix::at(int i, int j)
{
	return *(*(matrix + i) + j);
}
void Matrix::setAt(int i, int j, double val)
{
	*(*(matrix + i) + j) = val;
}
void Matrix::operator++()
{
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			++*(*(matrix + i) + j);
		}
	}
}
void Matrix::operator++(int)
{
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			(*(*(matrix + i) + j))++;
		}
	}
}
void Matrix::operator--()
{
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			--*(*(matrix + i) + j);
		}
	}
}
void Matrix::operator--(int)
{
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			(* (*(matrix + i) + j))--;
		}
	}
}
double** Matrix::getMatrix()
{
	return matrix;
}