#include <iostream>
#include "telephone.h"
//������� ������, ���-4, 4 �������

/*�������� ����������� �����, � ������������ � ���������. ������������������ � ���� ������������ ������,
���������� ������������� ��� ���������� � � ����������� ��� ������������� ������. ����� ������ ���������
����� serialize() ��� ���������� ������ ������ � ���� � ����� deserialize() ��� ������ ������ ������ �� �����
�� ��������� � ������� ����������, � ����� ������������� ������ serialize(const std::string& filename) � 
deserialize(const std::string& filename) ��� ������ � ������ � ��������� � ��������� ������.*/

/*������� 4
����� �������.
������: ������, ����� ��������, ��������� ��������� �����, ������� �� �����.
������� ��� �������� � ����. ���������� ������ ������� �������� � ������� ��������,
������� � � ������������ � �����������. � ������� ������� �������������� ������ ������� � 
��������� �� ��������� ��� �� 3 ������, � ��� ����� �� ����� ������� �������� � ���������. 
�� ������ ������ ��������� ��������� 0,5 ���. ������� ��� ���������� � ��������� ����� 
����������� �������.*/

int main()
{
	//�������� ���� ��������� � ���������� �� ������
	Phone* phone = new Phone();
	Phone* firstPhone;
	firstPhone = new Phone();
	firstPhone->setModel("iPhone 12 mini");
	firstPhone->setNumber("071 347 04 47");
	firstPhone->setBalance(50.0);
	Phone* secondPhone;
	secondPhone = new Phone("iPhone 7", "099 037 01 68", 10.0);
	//������ � ������� ������
	firstPhone->call(secondPhone->getNumber()); //12 �����
	firstPhone->call(secondPhone->getNumber()); //18 �����
	firstPhone->call("1337 228 666"); //5 �����
	firstPhone->call("099 037 01 68");  //11 ����� 
	firstPhone->call("071 044 47 347"); //30 �����
	//������ �� ������� ������
	secondPhone->call(firstPhone->getNumber()); //5 �����
	secondPhone->call(firstPhone->getNumber()); //18 �����
	secondPhone->call("044 47 347"); //18 �����
	secondPhone->call("037 01 68"); //23 �����
	secondPhone->call("1337 228 666"); //15 �����
	//������ � ����
	firstPhone->serialize();
	secondPhone->serialize("info.txt");
	//����� ���������� � ���������
	firstPhone->printInfo();
	secondPhone->printInfo();
	//���������� �� �����
	firstPhone->deserialize("info.txt");
	secondPhone->deserialize();
	//����� ���������� ����� ���������� �� �����(������ ��������� �������������� � ������)
	firstPhone->printInfo();
	secondPhone->printInfo();
	return 0;
}