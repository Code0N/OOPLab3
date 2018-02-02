// Memories from a Distant Past.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Stadium.h"
#include <clocale>
#include <iostream>
#include <iomanip>
#include <string>
#include "PStadium.h"
#include "FStadium.h"
#include "RStadium.h"

void screenOutput(char* str)
{
	std::cout << std::endl << str << std::endl << std::endl;
}


int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "Russian");
	
	screenOutput("Демонстрация класса 'Стадион'");

	//Создание стадионов
	Stadium* stadiums[3];
	stadiums[0] = new Stadium();
	stadiums[1] = new PStadium();
	stadiums[2] = new RStadium("ул. Переплюевская, 128, 256", "Газмяс", 10, 20000, 1000);
	//Создание стадионов

	//Сеттеры
	stadiums[0]->setAddress("ул. Костыльская, 15");
	stadiums[0]->setClubName("Ноголом");
	stadiums[0]->setSectorCount(100);
	stadiums[0]->setCapacity(100000);
	stadiums[0]->setAttendance(599999);
	//---
	stadiums[1]->setAddress("ул. именни Велосипеда, -1, -1");
	stadiums[1]->setClubName("BeerBand");
	stadiums[1]->setSectorCount(12);
	stadiums[1]->setCapacity(1000);
	stadiums[1]->setAttendance(300);
	//Сеттеры

	screenOutput("\n\n Текущие данные в объектах:");

	std::cout << "Адресс: " << stadiums[0]->getAddress() << std::endl << "Клуб: " << stadiums[0]->getClubName() << std::endl << "Количество секторов: " << stadiums[0]->getSectorCount() << std::endl << "Вместимость: " << stadiums[0]->getCapacity() << std::endl << "Посещаемость: " << stadiums[0]->getAttendance() <<std::endl << std::endl;
	std::cout << "Адресс: " << stadiums[1]->getAddress() << std::endl << "Клуб: " << stadiums[1]->getClubName() << std::endl << "Количество секторов: " << stadiums[1]->getSectorCount() << std::endl << "Вместимость: " << stadiums[1]->getCapacity() << std::endl << "Посещаемость: " << stadiums[1]->getAttendance() <<std::endl << std::endl;
	std::cout << "Адресс: " << stadiums[2]->getAddress() << std::endl << "Клуб: " << stadiums[2]->getClubName() << std::endl << "Количество секторов: " << stadiums[2]->getSectorCount() << std::endl << "Вместимость: " << stadiums[2]->getCapacity() << std::endl << "Посещаемость: " << stadiums[2]->getAttendance() <<std::endl << std::endl;
	stadiums[2]->serialize();
	stadiums[2]->serialize("serlog.log");
	std::cout << std::endl;

	for(char i = 0; i < 3; i++)
	{
		if((dynamic_cast<IPercentCalculate*>(stadiums[i])))
		{
			std::cout << "Процент заполнения стадиона PStadium = " << dynamic_cast<IPercentCalculate*>(stadiums[i])->calcPercent() << '%' <<  std::endl;
		}
	}
	

	system("pause");
	
	return 0;
}

