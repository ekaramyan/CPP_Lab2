#include <iostream>
#include"Fraction.h"
#include<string>

using namespace std;
//������� ������, ���-4, 4 �������

/*�������� ����� Fraction ��� ������������� ������������ ������ (��� ��������� ���� ����� ����� x/y).
����������� ��������� +, -, *, / ��� ������. ����������� ����� void reduce() ��� ���������� �����, � ����� ����������� ������:
- int gcd(int n, int m)
������� ��� ���������� ����������� ������ �������� ����� n � m;
- void printAsFraction(double decimal_fraction)
- void printAsFraction(char* decimal_fraction)
������������� ������ ������ ���������� ����� � ���� ������������
(��������, ��� �������� decimal_fraction = 0.43 �� ������ ������ ��������� 43/100, ��� 0.25 � 1/4 � �.�.).
����� ����������� � ���� ������������ ����� ������ ������� ���� ���������
�� ������ ������ � ��������� ����������� ������.
������������������ ������ ���������� ������. ������� ��������� �������� ������.
���������� �������� ��������, ���������, ��������� � ������� ������. ������� �� ����� ����������.
�������� ����� ���������� ������ ����������� ������� ������.*/
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
		cout << "�������� ��������:  " << endl;
		cout << "1.���������� ��� " << endl;
		cout << "2.����� ���������� ����� � ���� ������������" << endl;
		cout << "3.���������� �����" << endl;
		cout << "4.�������� ������" << endl;
		cout << "5.��������� ������" << endl;
		cout << "6.��������� ������" << endl;
		cout << "7.������� ������" << endl;
		cout << "8.���������� �������� ������: " << endl;
		cout << "9.�����" << endl;

		char fractChar[10];
		cin >> n;
		switch (n)
		{
		case 1:
			int n, m;
			cout << "������� n" << endl;
			cin >> n;
			cout << "������� m" << endl;
			cin >> m;
			cout << "���: " << Fraction::gcd(n, m) << endl;
			break;
		case 2:			
			cout << "������� ���������� ����� ��� ��������������: ( ����� ����� ) " << endl;
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
			cout << "������� ������ ��������" << endl;
			errorOption = true;
			break;
		}
	} while (errorOption);
}
