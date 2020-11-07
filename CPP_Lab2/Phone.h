#pragma once
#include <string>
class Phone
{
public:
	Phone(); // �����������
	Phone(int x, int y); // ����������� � �����������
	void setModel(const std::string& name); // �������
	void setPos(int x, int y);
	int getSpeed() const; // �������
	double getCharge() const;
	void moveLeft(); // ������������� �����
	void moveRight(); // ������������� ������
	void accelerate(); // ����������
	void slowDown(); // �����������
	// ������������ / ��������������:
	void serialize() const;
	void serialize(const std::string& filename) const;
	void deserialize();
	void deserialize(const std::string& filename);
	void printInfo() const; // ����� ���������� � ����
private:
	std::string name_; // ��� ������
	int xpos_, ypos_; // ���������� ������
	double charge_; // ������� ������ �������
	int speed_; // �������� (�� ������� ������������� �� ���� ���)
};
#include "Phone.h"
#include <iostream>
Phone::Phone() : Phone(5, 5)
{
}
Phone::Phone(int x, int y) : xpos_(x), ypos_(y), speed_(0), charge_(100.0)
{
}
void Phone::setModel(const std::string& name)
{
	name_ = name;
}
void Phone::setPos(int x, int y)
{
	xpos_ = x;
	ypos_ = y;
}
double Phone::getCharge() const
{
	return charge_;
}
int Phone::getSpeed() const
{
	return speed_;
}
void Phone::moveLeft()
{
	xpos_ -= speed_;
	charge_ -= speed_ * 3;
}
void Phone::moveRight()
{
	xpos_ += speed_;
	charge_ -= speed_ * 3;
}
void Phone::accelerate()
{
	speed_++;
}
void Phone::slowDown()
{
	if (speed_ > 1)
		speed_--;
}
void Phone::printInfo() const
{
	std::cout << name_ << " : ";
	std::cout << "( " << xpos_ << "," << ypos_ << " ) ";
	std::cout << "CHARGE: " << charge_ << std::endl;
}
void Phone::serialize() const
{
	// ...����� ��� ��� ���������� ������ ������ � ����...
}
void Phone::serialize(const std::string& filename) const
{
	//...
}
void Phone::deserialize()
{
	//...
}
void Phone::deserialize(const std::string& filename)
{
	//...
}
