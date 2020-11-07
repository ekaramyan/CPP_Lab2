#include <string>
#include <iostream>

using namespace std;

	//В главной функции можно написать, например, так:
	Phone p1(300, 400), p2, p3; // создаем три телефона
	p2.setPos(150, 200);
	p1.setName("Google Pixel");
	p2.setName("Iphone");
	p3.setName("Xiaomi");
	std::cout << "Before:" << std::endl;
	p1.printInfo();
	p2.printInfo();
	p3.printInfo();
	// ----------------------------------- имитация перемещений и ускорений роботов
	p1.accelerate();
	p1.moveRight();
	p2.moveRight();
	p3.moveRight();
	p1.accelerate();
	p2.accelerate();
	p1.moveRight();
	p2.moveRight();
	p3.moveRight();
	p1.accelerate();
	p1.moveRight();
	p2.moveRight();
	p3.moveRight();
	p2.accelerate();
	p2.accelerate();
	p1.moveRight();
	p2.moveRight();
	p3.moveRight();
	p3.accelerate();
	p1.moveRight();
	p2.moveRight();
	p3.moveRight();
	// -----------------------------------------------------------------------------
	std::cout << "\nAfter:" << std::endl;
	p1.printInfo();
	p2.printInfo();
	p3.printInfo();
	p1.serialize("D:\\Phones\\1.txt");
	p2.serialize("D:\\Phones\\2.txt");
	p3.serialize("D:\\Phones\\3.txt");