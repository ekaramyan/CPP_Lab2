#include <iostream>
#include "telephone.h"
//Карамян Эдуард, ИВТ-4, 4 вариант

/*Написать собственный класс, в соответствии с вариантом. Продемонстрировать в коде инкапсуляцию данных,
применение конструкторов без параметров и с параметрами для инициализации данных. Класс должен содержать
метод serialize() для сохранения данных класса в файл и метод deserialize() для чтения данных класса из файла
по умолчанию в текущей директории, а также перегруженные методы serialize(const std::string& filename) и 
deserialize(const std::string& filename) для работы с файлом с указанным в параметре именем.*/

/*Вариант 4
Класс ТЕЛЕФОН.
Данные: модель, номер телефона, последний набранный номер, остаток на счету.
Создать два телефона в куче. Установить данные первого телефона с помощью сеттеров,
второго – в конструкторе с параметрами. В главной функции проимитировать десять звонков – 
позвонить по нескольку раз на 3 номера, в том числе на номер другого телефона в программе. 
За каждую минуту разговора снимается 0,5 руб. Вывести всю информацию о телефонах после 
проведенных звонков.*/

int main()
{
	//создание двух телефонов и заполнение их данных
	Phone* phone = new Phone();
	Phone* firstPhone;
	firstPhone = new Phone();
	firstPhone->setModel("iPhone 12 mini");
	firstPhone->setNumber("071 347 04 47");
	firstPhone->setBalance(50.0);
	Phone* secondPhone;
	secondPhone = new Phone("iPhone 7", "099 037 01 68", 10.0);
	//звонки с первого номера
	firstPhone->call(secondPhone->getNumber()); //12 минут
	firstPhone->call(secondPhone->getNumber()); //18 минут
	firstPhone->call("1337 228 666"); //5 минут
	firstPhone->call("099 037 01 68");  //11 минут 
	firstPhone->call("071 044 47 347"); //30 минут
	//звонки со второго номера
	secondPhone->call(firstPhone->getNumber()); //5 минут
	secondPhone->call(firstPhone->getNumber()); //18 минут
	secondPhone->call("044 47 347"); //18 минут
	secondPhone->call("037 01 68"); //23 минут
	secondPhone->call("1337 228 666"); //15 минут
	//запись в файл
	firstPhone->serialize();
	secondPhone->serialize("info.txt");
	//вывод информации о телефонах
	firstPhone->printInfo();
	secondPhone->printInfo();
	//сичтывание из файла
	firstPhone->deserialize("info.txt");
	secondPhone->deserialize();
	//вывод информации после считывания из файла(данные телефонов поменялисьдруг с другом)
	firstPhone->printInfo();
	secondPhone->printInfo();
	return 0;
}