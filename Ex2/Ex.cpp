#include <iostream>
#include"Fraction.h"
#include<string>

using namespace std;
//Карамян Эдуард, ИВТ-4, 4 вариант

/*Написать класс Fraction для представления обыкновенных дробей (как отношения двух целых чисел x/y).
Перегрузить операторы +, -, *, / для дробей. Реализовать метод void reduce() для сокращения дроби, а также статические методы:
- int gcd(int n, int m)
функция для нахождения наибольшего общего делителя чисел n и m;
- void printAsFraction(double decimal_fraction)
- void printAsFraction(char* decimal_fraction)
перегруженные методы вывода десятичной дроби в виде обыкновенной
(например, при значении decimal_fraction = 0.43 на экране должно вывестись 43/100, при 0.25 – 1/4 и т.д.).
Также реализовать в виде статического члена класса счетчик всех созданных
на данный момент в программе экземпляров дробей.
Продемонстрировать работу созданного класса. Создать несколько объектов дробей.
Произвести операции сложения, вычитания, умножения и деления дробей. Вывести на экран результаты.
Показать также результаты работы статических методов класса.*/
int Fraction::cnt = 0;

int main()
{
	setlocale(LC_ALL, "Rus");
	string str = "3/4";
	Fraction fract1(str);
	Fraction fractNull;
	str = "108/1890";
	Fraction fract2(str);

	bool errorOption = true;
	do
	{
	int n;
		cout << "Выберите действие:  " << endl;
		cout << "1.Нахождение НОД " << endl;
		cout << "2.Вывод десятичной дроби в виде обыкновенной" << endl;
		cout << "3.Сокращение дроби" << endl;
		cout << "4.Сложение дробей" << endl;
		cout << "5.Вычитание дробей" << endl;
		cout << "6.Умножение дробей" << endl;
		cout << "7.Деление дробей" << endl;
		cout << "8.Количество объектов класса: " << endl;
		cout << "9.Выход" << endl;

		char fractChar[10];
		cin >> n;
		switch (n)
		{
		case 1:
			int n, m;
			cout << "Введите n" << endl;
			cin >> n;
			cout << "Введите m" << endl;
			cin >> m;
			cout << "НОД: " << Fraction::gcd(n, m) << endl;
			break;
		case 2:			
			cout << "Введите десятичную дробь для преобразования: ( через точку ) " << endl;
			cin >> fractChar;
			Fraction::printAsFraction(fractChar);
			break;
		case 3:
			fract1.reduce();
			fract2.reduce();
			fract1.printFraction();
			fract2.printFraction();
			break;
		case 4:
			fractNull = fract1 + fract2;
			fractNull.reduce();
			fractNull.printFraction();
			break;
		case 5:
			fractNull = fract1 - fract2;
			fractNull.reduce();
			fractNull.printFraction();
			break;
		case 6:
			fractNull = fract1 * fract2;
			fractNull.reduce();
			fractNull.printFraction();
			break;
		case 7:
			fractNull = fract1 / fract2;
			fractNull.reduce();
			fractNull.printFraction();
			break;
		case 8:
			cout << Fraction:: getCnt() << endl;
			break;
		case 9:
			errorOption = false;
			break;
		default:
			cout << "Введите верную операцию" << endl;
			errorOption = true;
			break;
		}
	} while (errorOption);
}
