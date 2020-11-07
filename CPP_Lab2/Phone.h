#pragma once
#include <string>
class Phone
{
public:
	Phone(); // конструктор
	Phone(int x, int y); // конструктор с параметрами
	void setModel(const std::string& name); // сеттеры
	void setPos(int x, int y);
	int getSpeed() const; // геттеры
	double getCharge() const;
	void moveLeft(); // переместиться влево
	void moveRight(); // переместиться вправо
	void accelerate(); // ускориться
	void slowDown(); // замедлиться
	// сериализация / десериализация:
	void serialize() const;
	void serialize(const std::string& filename) const;
	void deserialize();
	void deserialize(const std::string& filename);
	void printInfo() const; // вывод информации о себе
private:
	std::string name_; // имя робота
	int xpos_, ypos_; // координаты робота
	double charge_; // уровень заряда батареи
	int speed_; // скорость (на сколько передвигается за один шаг)
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
	// ...здесь код для сохранения данных класса в файл...
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
